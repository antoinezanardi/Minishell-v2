/*
** parse_line.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb 12 16:18:29 2015 Antoine Zanardi
** Last update Fri Feb 13 11:51:32 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		parse_end(char *str)
{
  int		compt_str;
  int		compt_check;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      while (str[compt_str] != '\0' && str[compt_str] != ';')
	compt_str++;
      compt_check = compt_str;
      compt_check--;
      while (str[compt_check] == ' ' || str[compt_check] == '\t')
	compt_check--;
      if (str[compt_check] == '>' || str[compt_check] == '<' ||
	  str[compt_check] == '|' || str[compt_check] == ';')
	{
	  my_putstr("Bad placement of '");
	  my_putchar(str[compt_check]);
	  my_putstr("'\n");
	  return (1);
	}
      if (str[compt_str] == ';')
	compt_str++;
    }
  return (0);
}

int		parse_begin(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      pass_spaces(str, &compt_str);
      if (str[compt_str] == ';' || str[compt_str] == '|' ||
	  str[compt_str] == '<' || str[compt_str] == '>')
    	{
	  my_putstr("Bad placement of '");
	  my_putchar(str[compt_str]);
	  my_putstr("'\n");
	  return (1);
	}
      else
	{
	  while (str[compt_str] != '\0' && str[compt_str] != ';')
	    compt_str++;
	  if (str[compt_str] == ';')
	    compt_str++;
	}
    }
  return (0);
}

int		parse_multiple(char *str)
{
  int		compt_str;

  compt_str = -1;
  while (str[++compt_str] != '\0')
    {
      if (str[compt_str] == ';' && str[compt_str + 1] == ';')
	{
	  my_putstr("Multiple ';' are not allowed\n");
	  return (1);
	}
      else if ((str[compt_str] == '>' && str[compt_str + 1] == '<') ||
	       (str[compt_str] == '<' && str[compt_str + 1] == '>'))
	{
	  my_putstr("There are some problems with contrary redirection\n");
	  return (1);
	}
      else if (str[compt_str + 1] != '\0' && str[compt_str + 2] != '\0')
	if (str[compt_str] == '|' && str[compt_str + 1] == '|' &&
	    str[compt_str + 2] == '|')
	  {
	    my_putstr("Triple '|' or more are not allowed\n");
	    return (1);
	  }
    }
  return (0);
}

int		parse_redirection(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      if (str[compt_str + 1] != '\0' && str[compt_str + 2] != '\0')
	{
	  if (str[compt_str] == '>' && str[compt_str + 1] == '>' &&
	      str[compt_str + 2] == '>')
	    {
	      my_putstr("Too much '>' are not allowed\n");
	      return (1);
	    }
	  else if (str[compt_str] == '<' && str[compt_str + 1] == '<' &&
		   str[compt_str + 2] == '<')
	    {
	      my_putstr("Too much '<' are not allowed\n");
	      return (1);
	    }
	}
      compt_str++;
    }
  return (0);
}

int		parse_line(char *str)
{
  int		compt_str;

  compt_str = 0;
  pass_spaces(str, &compt_str);
  if (str[compt_str] == '\0' || str[compt_str] == ';' ||
      str[compt_str] == '<' || str[compt_str] == '>' ||
      str[compt_str] == '|')
    return (1);
  if (parse_multiple(str) == 1 || parse_redirection(str) == 1)
    return (1);
  if (parse_end(str) == 1 || parse_begin(str) == 1)
    return (1);
  if (parse_consecutive(str) == 1)
    return (1);
  return (0);
}
