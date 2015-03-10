/*
** access_command.c for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Jan 14 11:06:17 2015 Antoine Zanardi
** Last update Thu Mar  5 14:25:25 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	"minishell.h"
#include	"my.h"

char		*path_comm(char **path, char *commande)
{
  char		*real_path;
  int		compt_tab;

  compt_tab = 0;
  if (access(commande, F_OK) == 0)
    return (commande);
  while (path[compt_tab] != '\0')
    {
      real_path = my_str_paste(path[compt_tab], commande);
      if (access(real_path, F_OK) == 0)
	return (real_path);
      compt_tab++;
    }
  return (NULL);
}

void		my_command(char **line, char **path, t_list **li)
{
  int		child;
  int		status;
  char		*real_path;
  char		**env;

  real_path = path_comm(path, line[0]);
  env = list_to_wordtab(li);
  child = fork();
  if (child == 0)
    {
      if (execve(real_path, line, env) == -1)
	my_putstr("This is not a valid program\n");
      exit(0);
    }
  else
    wait(&status);
}

void		no_command(char *str)
{
  my_putstr(str);
  my_putstr(": Command not found\n");
}

char		*path_command(char **path, char *commande)
{
  char		*real_path;
  int		compt_tab;

  compt_tab = 0;
  if (path == NULL)
    return (NULL);
 if (access(commande, F_OK) == 0)
    return (commande);
  while (path[compt_tab] != '\0')
    {
      real_path = my_str_paste(path[compt_tab], commande);
      if (access(real_path, F_OK) == 0)
	return (real_path);
      compt_tab++;
    }
  return (NULL);
}

int		find_command(char *str, char **path)
{
  if (path_command(path, str) != NULL)
    return (0);
  return (1);
}
