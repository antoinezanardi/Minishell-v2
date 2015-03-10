/*
** my_cd.c<2> for my_cd in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb 19 09:40:45 2015 Antoine Zanardi
** Last update Thu Mar  5 10:34:03 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

char		*pwd_paste(char *str1, char *str2)
{
  char		*dest;
  int		compt_str;
  int		compt_str2;

  if ((dest = malloc(sizeof(char) *
		     (unsigned int)(my_strlen(str1) + my_strlen(str2)
		      + 1))) == NULL)
    my_putstr_error(1);
  if (dest == NULL)
    return (NULL);
  compt_str = 0;
  compt_str2 = 0;
  while (str1[compt_str] != '\0')
    {
      dest[compt_str] = str1[compt_str];
      compt_str++;
    }
  while (str2[compt_str2] != '\0')
    {
      dest[compt_str] = str2[compt_str2];
      compt_str2++;
      compt_str++;
    }
  dest[compt_str] = '\0';
  return (dest);
}

char		*get_my_pwd(t_list **env_list)
{
  t_list	*tmp;
  char		*pwd;

  tmp = *env_list;
  pwd = NULL;
  while (tmp != NULL)
    {
      if (my_strcmp("PWD=", tmp->str, 0) == 0)
	pwd = only_pwd(tmp->str);
      tmp = tmp->next;
    }
  if (pwd != NULL)
    return (pwd);
  my_putstr("PWD couldn't be found\n");
  return (NULL);
}

char		*get_my_oldpwd(t_list **env_list)
{
  t_list	*tmp;
  char		*pwd;

  tmp = *env_list;
  pwd = NULL;
  while (tmp != NULL)
    {
      if (my_strcmp("OLDPWD=", tmp->str, 0) == 0)
	pwd = only_pwd(tmp->str);
      tmp = tmp->next;
    }
  if (pwd != NULL)
    return (pwd);
  my_putstr("OLDPWD couldn't be found\n");
  return (NULL);
}

char		*swap_pwds(t_list **env_list)
{
  t_list	*tmp;
  char		*old_pwd;
  char		*pwd;

  tmp = *env_list;
  old_pwd = NULL;
  pwd = NULL;
  while (tmp != NULL)
    {
      if (my_strcmp("OLDPWD=", tmp->str, 0) == 0)
	old_pwd = only_pwd(tmp->str);
      else if (my_strcmp("PWD=", tmp->str, 0) == 0)
      	pwd = only_pwd(tmp->str);
      tmp = tmp->next;
    }
  if (old_pwd != NULL && pwd != NULL)
    {
      my_set_envpwd(env_list, pwd_paste("PWD=", old_pwd));
      my_set_envpwd(env_list, pwd_paste("OLDPWD=", pwd));
      return (old_pwd);
    }
  return (NULL);
}

void		my_cd(char **tab_line, t_list **env_list)
{
  static char	*old_pwd;

  if (tab_line[1] == '\0')
    {
      if (get_my_oldpwd(env_list) == NULL)
	return;
      home_cd(env_list, &old_pwd);
    }
  else if (tab_line[1][0] == '-' && tab_line[1][1] == '\0' &&
	   get_my_pwd(env_list) != NULL && get_my_oldpwd(env_list) != NULL)
    {
      old_pwd = swap_pwds(env_list);
      if (chdir(old_pwd) == -1)
	my_putstr("Folder couldn't be found\n");
    }
  else if (get_my_pwd(env_list) != NULL)
    {
      if (chdir(tab_line[1]) == -1)
	my_putstr("Folder couldn't be found\n");
      else
	if (tab_line[1][0] == '/' && find_double_slash(tab_line[1]) == 0)
	  old_pwd = change_direct_pwd(tab_line[1], env_list);
	else if (get_my_pwd(env_list) != NULL)
	  old_pwd = change_current_pwd(tab_line[1], env_list);
    }
}
