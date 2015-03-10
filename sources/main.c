/*
** main.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 11 11:13:11 2015 Antoine Zanardi
** Last update Fri Mar  6 16:09:50 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"get_next_line.h"
#include	"minishell.h"
#include	"my.h"

int		my_shell(char **env, char **tab_path)
{
  t_list	*list;
  t_command	*command;
  char		*line;

  list = NULL;
  add_env_to_list(env, &list);
  while (42)
    {
      command = NULL;
      prompt(&list);
      if ((line = get_next_line(0)) == NULL)
	exit(1);
      tab_path = path_to_tab(&list, tab_path);
      if (parse_line(line) == 0)
	{
	  line_to_list(line, &command);
	  if (parsing_list(&command) == 0)
	    choose_type(&command, tab_path, &list);
	}
      free(command);
    }
}

int		main(int argc, char **argv, char **env)
{
  char		**tab_path;

  (void)argv;
  tab_path = NULL;
  signal(SIGINT, &signal_c);
  if (argc != 1)
    return (0);
  my_shell(env, tab_path);
  return (0);
}
