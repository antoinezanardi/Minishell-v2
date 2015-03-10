/*
** line_to_tab.c for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb 12 15:24:10 2015 Antoine Zanardi
** Last update Thu Mar  5 10:51:57 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"get_next_line.h"
#include	"minishell.h"
#include	"my.h"

unsigned int	nb_command(char *str, int compt_str)
{
  unsigned int	words;

  words = 0;
  while (str[compt_str] != '\0' && str[compt_str] != '|' &&
	 str[compt_str] != '<' && str[compt_str] != '>' &&
	 str[compt_str] != ';')
    {
      pass_spaces(str, &compt_str);
      while (str[compt_str] != '\0' && str[compt_str] != '|' &&
	     str[compt_str] != '<' && str[compt_str] != '>' &&
	     str[compt_str] != ';' && str[compt_str] != ' ' &&
	     str[compt_str] != '\t')
	compt_str++;
      pass_spaces(str, &compt_str);
      if (str[compt_str] != '\0' && str[compt_str] != '|' &&
	  str[compt_str] != '<' && str[compt_str] != '>' &&
	  str[compt_str] != ';')
	words++;
    }
  return (words + 1);
}

unsigned int	let_com(char *str, int compt_str)
{
  unsigned int	letters;

  letters = 0;
  while (str[compt_str] != '\0' && str[compt_str] != '|' &&
	 str[compt_str] != '<' && str[compt_str] != '>' &&
	 str[compt_str] != ';' && str[compt_str] != ' ' &&
	 str[compt_str] != '\t')
    {
      compt_str++;
      letters++;
    }
  return (letters);
}

void		line_to_tab(t_command **com, char *str, int *compt_str, int wo)
{
  char		**tab;
  int		letters;

  if ((tab = malloc(sizeof(char *) *
		    (nb_command(str, *compt_str) + 1))) == NULL)
    my_putstr_error(1);
  while (str[*compt_str] != '\0' && str[*compt_str] != '|' &&
	 str[*compt_str] != '<' && str[*compt_str] != '>' &&
	 str[*compt_str] != ';')
    {
      letters = 0;
      if ((tab[wo] = malloc(sizeof(char) *
			       let_com(str, *compt_str) + 1)) == NULL)
	my_putstr_error(1);
      while (str[*compt_str] != '\0' && str[*compt_str] != '|' &&
	     str[*compt_str] != '<' && str[*compt_str] != '>' &&
	     str[*compt_str] != ';' && str[*compt_str] != ' ' &&
	     str[*compt_str] != '\t')
	tab[wo][letters++] = str[(*compt_str)++];
      pass_spaces(str, compt_str);
      tab[wo++][letters] = '\0';
    }
  tab[wo] = '\0';
  ta_list(tab, str, *compt_str, com);
}
