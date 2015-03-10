/*
** my_lists.c for my_lists in /home/zanard_a/rendu/Librairie/Librairie_off
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:19:28 2014 Antoine Zanardi
** Last update Sun Mar  8 11:51:19 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		add_top_list(t_list **list, char *str)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (0);
  elem->str = str;
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

int		add_bot_list(t_list **list, char *str)
{
  t_list	*elem;
  t_list	*tmp;

  if ((*list) == NULL)
    return (add_top_list(list, str));
  elem = malloc(sizeof(t_list));
  if (elem == NULL)
    return (0);
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->str = str;
  elem->next = NULL;
  elem->prev = tmp;
  tmp->next = elem;
  return (0);
}

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
