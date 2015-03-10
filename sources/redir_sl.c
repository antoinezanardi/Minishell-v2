/*
** redir_sl.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Feb 17 19:12:24 2015 Antoine Zanardi
** Last update Thu Mar  5 14:00:53 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	"minishell.h"
#include	"my.h"
#include	"get_next_line.h"

void		redir_sl_son(int *fd, t_command *tmp, char *path, char **env)
{
  if ((*fd = open(tmp->next->tab[0], O_RDONLY)) == -1)
    {
      my_putstr("File couldn't be found\n");
      return;
    }
  if (dup2(*fd, 0) == -1)
    my_putstr_error(4);
  if (execve(path, tmp->tab, env) == -1)
    my_putstr("This is not a valid program\n");
}

void		redir_sl(t_command **cmd, char **path, t_list **li)
{
  int		child;
  int		fd;
  char		*real_path;
  char		**env;
  t_command	*tmp;

  tmp = *cmd;
  real_path = path_comm(path, tmp->tab[0]);
  env = list_to_wordtab(li);
  if ((child = fork()) == -1)
    my_putstr_error(3);
  if (child == 0)
    {
      redir_sl_son(&fd, tmp, real_path, env);
      close(fd);
      exit(0);
   }
  wait(NULL);
  (*cmd) = (*cmd)->next->next;
}
