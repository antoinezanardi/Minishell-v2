/*
** my_exit.c for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Jan 21 17:15:58 2015 Antoine Zanardi
** Last update Sun Mar  8 13:48:51 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		str_is_nbr(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (str[compt_str] == '-')
    compt_str++;
  if (str[compt_str] == '\0')
    return (1);
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] >= '0' && str[compt_str] <= '9')
	compt_str++;
      else
	{
	  my_putstr("Wrong return value for exit\n");
	  return (1);
	}
    }
  return (0);
}

void		my_exit(char *status, int mode)
{
  if (mode == 1)
    {
      my_putstr("Minishell says bye bye !\n");
      exit(0);
    }
  else if (mode == 2 && str_is_nbr(status) == 0)
    {
        my_putstr("Minishell says bye bye !\n");
	exit(my_getnbr(status));
    }
}

void		treat_exit(char **tab_line)
{
  if (my_strcmp_exact("exit", tab_line[0], 0) == 0)
    {
      if (tab_line[1] == '\0')
	my_exit("0", 1);
      else
	my_exit(tab_line[1], 2);
    }
}
