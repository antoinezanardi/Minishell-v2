/*
** unset_env.c for minishell2	 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb 14 23:25:39 2015 Antoine Zanardi
** Last update Thu Mar  5 10:21:39 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"minishell.h"
#include	"my.h"

int		len_unset(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    compt_str++;
  return (compt_str);
}

char		*only_var_unset(char *str)
{
  char		*dest;
  int		compt_str;

  compt_str = 0;
  if ((dest = malloc(sizeof(char) *
		     ((unsigned int)(len_unset(str) + 1)))) == NULL)
    my_putstr_error(1);
  while (str[compt_str] != '\0')
    {
      dest[compt_str] = str[compt_str];
      compt_str++;
    }
  dest[compt_str] = '\0';
  return (dest);
}

int		parse_unsetenv(char *str)
{
  if (str[0] == '\0')
    {
      my_putstr("No line to delete to env\n");
      return (1);
    }
  if (str[0] == '=')
    {
      my_putstr("Usage : ~Delete USER~ 'unsetenv USER'\n");
      return (1);
    }
  return (0);
}

void		remove_elem_list(t_list *tmp, t_list **list)
{
  if (tmp->prev == NULL && tmp->next == NULL)
    (*list) = NULL;
  else if (tmp->prev == NULL)
    {
      *list = (*list)->next;
      tmp->next->prev = NULL;
    }
  else if (tmp->next == NULL)
    tmp->prev->next = NULL;
  else
    {
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
    }
}

int		my_unset_env(t_list **env_list, char **tab_line)
{
  t_list	*tmp;
  char		*str;
  char		*eq_str;

  tmp = *env_list;
  if (tab_line[1] == '\0')
    {
      my_putstr("Choose a variable to unset\n");
      return (1);
    }
  str = tab_line[1];
  if (parse_unsetenv(str) == 1)
    return (1);
  while (tmp != NULL)
    {
      eq_str = only_var_unset(str);
      if (my_strcmp(eq_str, tmp->str, 0) == 0)
	{
	  remove_elem_list(tmp, env_list);
	  return (0);
	}
      tmp = tmp->next;
    }
  my_putstr("The variable couldn't be found\n");
  return (1);
}
