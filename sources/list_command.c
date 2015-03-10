/*
** list_command.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb 12 13:30:18 2015 Antoine Zanardi
** Last update Thu Mar  5 10:47:50 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		command_top_list(char **tab, t_command **command, int type)
{
  t_command	*elem;

  if ((elem = malloc(sizeof(t_command))) == NULL)
    my_putstr_error(1);
  elem->tab = tab;
  elem->type = type;
  elem->next = *command;
  elem->prev = NULL;
  if (*command != NULL)
    (*command)->prev = elem;
  *command = elem;
  return (0);
}

int		command_bot_list(char **tab, t_command **command, int type)
{
  t_command	*elem;
  t_command	*tmp;

  if ((*command) == NULL)
    return (command_top_list(tab, command, type));
  if ((elem = malloc(sizeof(t_command))) == NULL)
    my_putstr_error(1);
  if (elem == NULL)
    my_putstr_error(1);
  tmp = *command;
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->tab = tab;
  elem->type = type;
  elem->next = NULL;
  elem->prev = tmp;
  tmp->next = elem;
  return (0);
}

void		ta_list(char **tab, char *str, int compt_str, t_command **com)
{
  if (str[compt_str] == '\0' || str[compt_str] == ';')
    command_bot_list(tab, com, 0);
  else if (str[compt_str] == '>' && str[compt_str + 1] != '>')
    command_bot_list(tab, com, 1);
  else if (str[compt_str] == '>' && str[compt_str + 1] == '>')
    command_bot_list(tab, com, 2);
  else if (str[compt_str] == '<' && str[compt_str + 1] != '<')
    command_bot_list(tab, com, 3);
  else if (str[compt_str] == '<' && str[compt_str + 1] == '<')
    command_bot_list(tab, com, 4);
  else if (str[compt_str] == '|')
    command_bot_list(tab, com, 5);
}

int		line_to_list(char *str, t_command **command)
{
  int		compt_str;
  int		words;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      words = 0;
      pass_spaces(str, &compt_str);
      line_to_tab(command, str, &compt_str, words);
      while (str[compt_str] != '\0' &&
	     (str[compt_str] == '|' || str[compt_str] == '<' ||
	      str[compt_str] == '>' || str[compt_str] == ';'))
	compt_str++;
    }
  return (0);
}
