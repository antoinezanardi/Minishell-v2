/*
** parse_the_list.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Feb 24 09:37:39 2015 Antoine Zanardi
** Last update Thu Mar  5 14:51:15 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		parsing_list(t_command **command)
{
  t_command	*tmp;

  tmp = *command;
  while (tmp != NULL)
    {
      if ((tmp->type == 1 || tmp->type == 2 ||
	  tmp->type == 3 || tmp->type == 4 ||
	   tmp->type == 5) && tmp->next == NULL)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}
