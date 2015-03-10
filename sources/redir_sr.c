/*
** redir_sl.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Feb 17 09:39:57 2015 Antoine Zanardi
** Last update Thu Mar  5 13:50:13 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<fcntl.h>
#include	"get_next_line.h"
#include	"minishell.h"
#include	"my.h"

int		redir_sr_son(int *pipefd, char *path, char **line, char **env)
{
  if (dup2(pipefd[1], 1) == -1)
    my_putstr_error(4);
  if (dup2(pipefd[0], 0) == -1)
    my_putstr_error(4);
  if (execve(path, line, env) == -1)
    my_putstr("This is not a valid program\n");
  close(pipefd[0]);
  close(pipefd[1]);
  exit(0);
}

void		write_file_sr(int *pipefd, char *file)
{
  int		fd;
  char		buffer[BUFFER_SIZE];
  long		ret;

  close(pipefd[1]);
  if ((fd = open(file, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR |
		 S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    {
      my_putstr("File couldn't be created, red\n");
      return;
    }
  while ((ret = read(pipefd[0], buffer, BUFFER_SIZE - 1)) > 0)
    {
      buffer[ret] = '\0';
      write(fd, buffer, (unsigned long)ret);
    }
  close(fd);
  close(pipefd[0]);
}

void		redir_sr(t_command **cmd, char **path, t_list **li)
{
  t_command	*tmp;
  int		child;
  char		*real_path;
  char		**env;
  int		pipefd[2];

  tmp = *cmd;
  real_path = path_comm(path, tmp->tab[0]);
  env = list_to_wordtab(li);
  check_fork_error(&child, pipefd);
  if (child == 0)
    redir_sr_son(pipefd, real_path, tmp->tab, env);
  write_file_sr(pipefd, tmp->next->tab[0]);
  wait(NULL);
  (*cmd) = (*cmd)->next->next;
}
