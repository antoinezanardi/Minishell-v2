/*
** home_cd.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb 19 10:05:40 2015 Antoine Zanardi
** Last update Thu Feb 19 11:28:02 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"minishell.h"

void		home_cd(t_list **envlist, char **old_pwd)
{
  t_list	*tmp;

  tmp = *envlist;
  *old_pwd = get_my_pwd(envlist);
  while (tmp != NULL)
    {
      if (my_strcmp("HOME=", tmp->str, 0) == 0)
	{
	  if (chdir(pick_after_eq(tmp->str)) == -1)
	    {
	      my_putstr("Couldn't find home\n");
	      return;
	    }
	  my_set_envpwd(envlist, pwd_paste("PWD=", pick_after_eq(tmp->str)));
	  my_set_envpwd(envlist, pwd_paste("OLDPWD=", *old_pwd));
	  return;
	}
      tmp = tmp->next;
    }
  my_putstr("Couldn't find HOME\n");
}
