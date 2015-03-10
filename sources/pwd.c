/*
** pwd.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb 14 23:59:03 2015 Antoine Zanardi
** Last update Thu Mar  5 10:37:25 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"minishell.h"

int		len_pwd(char *str)
{
  int		compt_str;
  int		nb_pwd;

  compt_str = 0;
  nb_pwd = 0;
  while (str[compt_str] != '=')
    compt_str++;
  compt_str++;
  while (str[compt_str] != '\0')
    {
      compt_str++;
      nb_pwd++;
    }
  return (nb_pwd);
}

char		*only_pwd(char *str)
{
  int		compt_str;
  int		compt_dest;
  char		*dest;

  compt_str = 0;
  compt_dest = 0;
  while (str[compt_str] != '=')
    compt_str++;
  compt_str++;
  if ((dest = malloc(sizeof(char) * (unsigned int)len_pwd(str) + 1)) == NULL)
    return (NULL);
  while (str[compt_str] != '\0')
    {
      dest[compt_dest] = str[compt_str];
      compt_dest++;
      compt_str++;
    }
  dest[compt_dest] = '\0';
  return (dest);
}

int		parse_pwd(char *str)
{
  char		*pwd;

  pwd = only_pwd(str);
  if (access(pwd, F_OK) == -1)
    {
      my_putstr("The specified path is not correct for the variable\n");
      return (1);
    }
  return (0);
}

int		my_set_envpwd(t_list **env_list, char *str)
{
  char		*eq_env;
  char		*eq_str;
  t_list	*tmp;

  tmp = *env_list;
  if (parse_setenv(str) == 1)
    return (1);
  while (tmp != NULL)
    {
      eq_str = only_eq(str);
      eq_env = only_eq(tmp->str);
      if (my_strcmp_exact(eq_str, eq_env, 0) == 0)
	{
	  tmp->str = str;
	  return (0);
	}
      tmp = tmp->next;
    }
  add_bot_list(env_list, str);
  return (0);
}
