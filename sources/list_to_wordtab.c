/*
** list_to_wordtab.c for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Jan 21 15:44:11 2015 Antoine Zanardi
** Last update Thu Mar  5 10:43:29 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		nb_var(t_list **list)
{
  int		compt_var;
  t_list	*tmp;

  compt_var = 1;
  tmp = *list;
  while (tmp != NULL)
    {
      compt_var++;
      tmp = tmp->next;
    }
  free(tmp);
  return (compt_var);
}

char		**list_to_wordtab(t_list **list)
{
  t_tabline	tabline;
  t_list	*tmp;
  char		**tab;

  tabline.word = 0;
  if ((tab = malloc(sizeof(char *) * (unsigned int)nb_var(list))) == NULL)
    return (NULL);
  tmp = *list;
  while (tmp != NULL)
    {
      tabline.letters = 0;
      if ((tab[tabline.word] = malloc(sizeof(char) * (unsigned int)
				      (my_strlen(tmp->str) + 1))) == NULL)
	return (NULL);
      while (tmp->str[tabline.letters] != '\0')
	{
	  tab[tabline.word][tabline.letters] = tmp->str[tabline.letters];
	  tabline.letters++;
	}
      tab[tabline.word][tabline.letters] = '\0';
      tmp = tmp->next;
      tabline.word++;
    }
  tab[tabline.word] = '\0';
  return (tab);
}
