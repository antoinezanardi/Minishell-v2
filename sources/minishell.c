/*
** minishell.c for minshell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 13 12:04:31 2015 Antoine Zanardi
** Last update Sun Mar  8 13:49:08 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"minishell.h"
#include	"my.h"

void		output_command(char **tab_line, char **tab_path, t_list **env)
{
  treat_exit(tab_line);
  if (find_command(tab_line[0], tab_path) == 0)
    my_command(tab_line, tab_path, env);
  else if (my_strcmp_exact("env", tab_line[0], 0) == 0)
    my_show_list(*env);
  else if (my_strcmp_exact("setenv", tab_line[0], 0) == 0)
    my_set_env(env, tab_line);
  else if (my_strcmp_exact("unsetenv", tab_line[0], 0) == 0)
    my_unset_env(env, tab_line);
  else if (my_strcmp_exact("cd", tab_line[0], 0) == 0)
    my_cd(tab_line, env);
  else
    no_command(tab_line[0]);
}

void		choose_type(t_command **command, char **tab_path, t_list **env)
{
  t_command	*tmp;

  tmp = *command;
  while (tmp != NULL)
    {
      if (tmp->type == 0)
	{
	  output_command(tmp->tab, tab_path, env);
	  tmp = tmp->next;
	}
      else if (tmp->type == 5)
	pipe_mult(&tmp, tab_path, env);
      else if (tmp->type == 1)
	redir_sr(&tmp, tab_path, env);
      else if (tmp->type == 2)
	redir_dr(&tmp, tab_path, env);
      else if (tmp->type == 3)
	redir_sl(&tmp, tab_path, env);
      else
      	tmp = tmp->next;
    }
}
