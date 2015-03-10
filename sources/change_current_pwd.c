/*
** change_current_pwd.c for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Jan 23 12:23:07 2015 Antoine Zanardi
** Last update Mon Feb  2 10:04:50 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

char		*get_my_folder(char *str, int *compt_str)
{
  int		compt_dest;
  char		*dest;

  compt_dest = 0;
  if ((dest = malloc(sizeof(char) * 50 + 1)) == NULL)
    return (NULL);
  while (str[*compt_str] != '/' && str[*compt_str] != '\0')
    {
      dest[compt_dest] = str[*compt_str];
      compt_dest++;
      *compt_str = *compt_str + 1;
    }
  dest[compt_dest] = '/';
  compt_dest++;
  dest[compt_dest] = '\0';
  return (dest);
}

void		treat_current_pwd(int *co_str, int *co, char *dest)
{
  if (*co != 1)
    {
      *co = *co - 1;
      if (dest[*co] == '/')
	*co = *co - 1;
      while (dest[*co] != '/')
	*co = *co - 1;
      *co = *co + 1;
      dest[*co] = '\0';
    }
  *co_str = *co_str + 2;
}

void		init_current_pwd(t_list **li, char *dest, int *co_str, int *co)
{
  dest = get_my_pwd(li);
  *co = 0;
  *co_str = 0;
  while (dest[*co] != '\0')
    *co = *co + 1;
}

static void	get_end_dest(char *dest, int *compt_dest, int *compt_str)
{
  while (dest[*compt_dest] != '\0')
    *compt_dest = *compt_dest + 1;
  *compt_str = *compt_str + 1;
}

char		*change_current_pwd(char *pwd, t_list **list)
{
  char		*dest;
  char		*old_pwd;
  char		*folder;
  int		compt_dest;
  int		compt_str;

  dest = get_my_pwd(list);
  old_pwd = NULL;
  init_current_pwd(list, dest, &compt_str, &compt_dest);
  while (pwd[compt_str] != '\0')
    {
      if (pwd[compt_str] == '.' && pwd[compt_str + 1] != '.')
	compt_str++;
      else if (pwd[compt_str] == '.' && pwd[compt_str + 1] == '.')
	treat_current_pwd(&compt_str, &compt_dest, dest);
      else
	{
	  folder = get_my_folder(pwd, &compt_str);
	  dest = pwd_paste(dest, folder);
	  get_end_dest(dest, &compt_dest, &compt_str);
	}
      pass_the_slash(pwd, &compt_str);
    }
  apply_pwd(list, old_pwd, dest);
  return (old_pwd);
}
