/*
** pipe.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Feb 17 13:29:11 2015 Antoine Zanardi
** Last update Thu Mar  5 13:52:00 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	"minishell.h"
#include	"my.h"

void		check_fork_error(int *child, int *pipefd)
{
  if (pipe(pipefd) == -1)
    my_putstr_error(2);
  if ((*child = fork()) == -1)
    my_putstr_error(3);
}

int		father_pipe(t_command *tmp, int *pipefd, char *pa, char **env)
{
  if (tmp->prev != NULL && tmp->prev->type == 5)
    {
      close(pipefd[1]);
      if (dup2(pipefd[0], 0) == -1)
	my_putstr_error(4);
    }
  if (execve(pa, tmp->tab, env) == -1)
    my_putstr("This is not a valid program\n");
  exit(0);
}

int		recur_pipe(t_command *tmp, t_list **li, char **path)
{
  int		pipefd[2];
  int		child;
  char		*real_path;
  char		**env;

  real_path = path_comm(path, tmp->tab[0]);
  env = list_to_wordtab(li);
  child = 1;
  if (tmp->prev != NULL && tmp->prev->type == 5)
    check_fork_error(&child, pipefd);
  if (child == 0)
    {
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
	my_putstr_error(4);
      recur_pipe(tmp->prev, li, path);
    }
  else
    father_pipe(tmp, pipefd, real_path, env);
  return (0);
}

void		pipe_mult(t_command **co, char **path, t_list **li)
{
  t_command	*tmp;
  int		child;

  tmp = *co;
  while (tmp->type == 5)
    tmp = tmp->next;
  if ((child = fork()) == -1)
    my_putstr_error(3);
  if (child == 0)
    recur_pipe(tmp, li, path);
  else
    {
      wait(NULL);
      while ((*co)->type == 5)
	(*co) = (*co)->next;
      (*co) = (*co)->next;
    }
}
