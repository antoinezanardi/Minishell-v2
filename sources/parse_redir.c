/*
** parse_redir.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 13 11:41:26 2015 Antoine Zanardi
** Last update Fri Feb 13 11:55:01 2015 Antoine Zanardi
*/

#include	"minishell.h"
#include	"my.h"

int		parse_consecutive(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] == ';' || str[compt_str] == '<' ||
	  str[compt_str] == '>' || str[compt_str] == '|')
	{
	  if ((str[compt_str] == '>' && str[compt_str + 1] == '>') ||
	      (str[compt_str] == '<' && str[compt_str + 1] == '<') ||
	      (str[compt_str] == '|' && str[compt_str + 1] == '|'))
	    compt_str = compt_str + 2;
	  else
	    compt_str++;
	  pass_spaces(str, &compt_str);
	  if (str[compt_str] == ';' || str[compt_str] == '<' ||
	      str[compt_str] == '>' || str[compt_str] == '|')
	    {
	      my_putstr("Consecutive redirections / pipes are not allowed\n");
	      return (1);
	    }
	}
      compt_str++;
    }
  return (0);
}
