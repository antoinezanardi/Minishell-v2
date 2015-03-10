/*
** prompt.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 11 11:37:14 2015 Antoine Zanardi
** Last update Thu Mar  5 10:58:55 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		default_prompt(int *action)
{
  *action += 1;
  my_putstr("$ ");
  my_putchar('(');
  my_put_nbr(*action);
  my_putchar(')');
  my_putstr("~> ");
  return (0);
}

int		display_prompt(char *str, int *action)
{
  char		*user;

  if ((user = pick_after_eq(str)) != NULL)
    {
      *action += 1;
      my_putstr(user);
      my_putstr(" (");
      my_put_nbr(*action);
      my_putchar(')');
      my_putstr("~> ");
    }
  else
    default_prompt(action);
  return (0);
}

int		prompt(t_list **list)
{
  t_list	*tmp;
  static int	action = 0;

  tmp = *list;
  while (tmp != NULL)
    {
      if (my_strcmp("USER=", tmp->str, 0) == 0)
	return(display_prompt(tmp->str, &action));
      tmp = tmp->next;
    }
  return (default_prompt(&action));
}
