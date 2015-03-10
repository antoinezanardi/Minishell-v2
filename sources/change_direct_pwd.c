/*
** change_pwd.c for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jan 22 15:21:26 2015 Antoine Zanardi
** Last update Thu Mar  5 10:34:32 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		find_double_slash(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] == '/')
	{
	  if (str[compt_str + 1] == '/')
	    {
	      my_putstr("Multiple / are not allowed in change directory\n");
	      return (1);
	    }
	}
      compt_str++;
    }
  return (0);
}

void		treat_direct_pwd(char *str, int *compt_str, char *dest, int *co)
{
  if (str[*compt_str] == '.' && str[*compt_str + 1] != '.')
    *compt_str = *compt_str + 2;
  else if (str[*compt_str] == '.' && str[*compt_str + 1] == '.')
    {
      *compt_str = *compt_str + 3;
      if (*co != 1)
	{
	  *co =  *co - 2;
	  while (dest[*co] != '/')
	    *co = *co - 1;
	  *co = *co + 1;
	}
    }
  else if (str[*compt_str] != '\0')
    {
      dest[*co] = str[*compt_str];
      *co = *co + 1;
      *compt_str = *compt_str + 1;
    }
}

void		pass_the_slash(char *pwd, int *compt_str)
{
  if (pwd[*compt_str] == '/')
    *compt_str = *compt_str + 1;
}

void		apply_pwd(t_list **list, char *old_pwd, char *dest)
{
  if ((old_pwd = get_my_pwd(list)) == NULL)
    {
      old_pwd = pwd_paste("OLDPWD=", dest);
      my_set_envpwd(list, pwd_paste("OLDPWD=", dest));
    }
  else
    my_set_envpwd(list, pwd_paste("OLDPWD=", old_pwd));
  my_set_envpwd(list, pwd_paste("PWD=", dest));
}

char		*change_direct_pwd(char *str, t_list **list)
{
  char		*dest;
  char		*old_pwd;
  int		compt_str;
  int		compt_dest;

  compt_str = 1;
  compt_dest = 0;
  old_pwd = NULL;
  if ((dest = malloc(sizeof(char) * (unsigned int)my_strlen(str) + 1)) == NULL)
    return (NULL);
  dest[compt_dest] = '/';
  compt_dest++;
  while (str[compt_str] != '\0')
    treat_direct_pwd(str, &compt_str, dest, &compt_dest);
  dest[compt_dest] = '\0';
  apply_pwd(list, old_pwd, dest);
  return (old_pwd);
}
