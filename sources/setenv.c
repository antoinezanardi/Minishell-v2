/*
** setenv.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb 14 23:51:58 2015 Antoine Zanardi
** Last update Thu Mar  5 10:33:38 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"minishell.h"

int		len_eq(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '=')
    compt_str++;
  compt_str++;
  return (compt_str);
}

char		*only_eq(char *str)
{
  char		*dest;
  int		compt_str;

  compt_str = 0;
  if ((dest = malloc(sizeof(char) * (unsigned int)(len_eq(str) + 1))) == NULL)
      return (NULL);
  while (str[compt_str] != '=')
    {
      dest[compt_str] = str[compt_str];
      compt_str++;
    }
  dest[compt_str] = str[compt_str];
  compt_str++;
  dest[compt_str] = '\0';
  return (dest);
}

int		parse_eq(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (str[0] == '=')
    return (1);
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] == '=')
	return (0);
      compt_str++;
    }
  return (1);
}

int		parse_setenv(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (str[0] == '\0')
    {
      my_putstr("No line to add to env\n");
      return (1);
    }
  if (parse_eq(str) == 1)
    {
      my_putstr("To set a variable env, you need an '=' and a variable\n");
      return (1);
    }
  while (str[compt_str] != '=')
    compt_str++;
  if (str[compt_str + 1] == '\0')
    {
      my_putstr("You need to fill the variable\n");
      return (1);
    }
  if (my_strcmp_exact("PWD=", only_eq(str), 0) == 0 ||
      my_strcmp_exact("OLDPWD=", only_eq(str), 0) == 0)
    if (parse_pwd(str) == 1)
      return (1);
  return (0);
}

int		my_set_env(t_list **env_list, char **tab_line)
{
  char		*eq_env;
  char		*eq_str;
  char		*str;
  t_list	*tmp;

  tmp = *env_list;
  if (tab_line[1] == '\0' || parse_setenv(tab_line[1]) == 1)
    return (1);
  str = tab_line[1];
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
