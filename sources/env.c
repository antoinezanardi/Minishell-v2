/*
** env.c for env in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 11 11:24:34 2015 Antoine Zanardi
** Last update Wed Feb 11 12:03:33 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

void		add_env_to_list(char **env, t_list **list)
{
  int		compt_tab;

  compt_tab = 0;
  while (env[compt_tab] != '\0')
    {
      add_bot_list(list, env[compt_tab]);
      compt_tab++;
    }
}
