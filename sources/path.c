/*
** path.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 11 12:22:16 2015 Antoine Zanardi
** Last update Thu Mar  5 10:54:37 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

char		*pick_path_line(t_list **list, int *compt_str, int *words)
{
  t_list	*tmp;

  if (*list == NULL)
    return (NULL);
  tmp = *list;
  *compt_str = 0;
  *words = 0;
  while (tmp != NULL)
    {
      if (my_strcmp("PATH=", tmp->str, 0) == 0)
	return(pick_after_eq(tmp->str));
      tmp = tmp->next;
    }
  return (NULL);
}

unsigned int	nb_path(char *str)
{
  int		compt_str;
  unsigned int	nb_path;

  compt_str = 0;
  nb_path = 1;
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] == ':' && str[compt_str + 1] != '\0')
	nb_path++;
      compt_str++;
    }
  return (nb_path);
}

unsigned int	nb_let(char *str, int compt_str)
{
  unsigned int	letters;

  letters = 0;
  while (str[compt_str] != ':' && str[compt_str] != '\0')
    {
      compt_str++;
      letters++;
    }
  return (letters);
}

void		my_show_tab(char **tab)
{
  int		compt_words;

  compt_words = 0;
  while (tab[compt_words] != NULL)
    {
      my_putstr(tab[compt_words]);
      my_putchar('\n');
      compt_words++;
    }
}

char		**path_to_tab(t_list **list, char **tab_path)
{
  char		*path_line;
  int		compt_str;
  int		words;
  int		letters;

  if ((path_line = pick_path_line(list, &compt_str, &words)) == NULL ||
      (tab_path = malloc(sizeof(char *) * (nb_path(path_line) + 1))) == NULL)
    return (NULL);
  while (path_line[compt_str] != '\0')
    {
      letters = 0;
      if ((tab_path[words] = malloc(sizeof(char) * (nb_let(path_line, compt_str)
						    + 1))) == NULL)
	return (NULL);
      while (path_line[compt_str] != ':' && path_line[compt_str] != '\0')
	{
	  tab_path[words][letters] = path_line[compt_str++];
	  letters++;
	}
      if (path_line[compt_str] == ':')
	compt_str++;
      tab_path[words++][letters] = '\0';
    }
  tab_path[words] = '\0';
  return (tab_path);
}
