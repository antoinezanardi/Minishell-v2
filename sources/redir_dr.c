/*
** redir_dr.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Feb 17 11:43:59 2015 Antoine Zanardi
** Last update Thu Mar  5 13:51:38 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"get_next_line.h"
#include	"minishell.h"
#include	"my.h"

void		write_file_dr(int *pipefd, char *file)
{
  int		fd;
  static char	buffer[BUFFER_SIZE];
  long		ret;

  close(pipefd[1]);
  if ((fd = open(file, O_RDWR | O_APPEND | O_CREAT, S_IRUSR |
		 S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    {
      my_putstr("File couldn't be created\n");
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

void		redir_dr(t_command **cmd, char **path, t_list **li)
{
  t_command	*tmp;
  int		child;
  int		pipefd[2];
  char		*real_path;
  char		**env;

  tmp = *cmd;
  real_path = path_comm(path, tmp->tab[0]);
  env = list_to_wordtab(li);
  check_fork_error(&child, pipefd);
  if (child == 0)
    redir_sr_son(pipefd, real_path, tmp->tab, env);
  wait(NULL);
  write_file_dr(pipefd, tmp->next->tab[0]);
  (*cmd) = (*cmd)->next->next;
}
