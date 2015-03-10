/*
** signal.c for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 13 17:46:58 2015 Antoine Zanardi
** Last update Fri Mar  6 15:52:56 2015 Antoine Zanardi
*/

#include	<sys/wait.h>
#include	"minishell.h"

void		signal_c(int signal)
{
  signal++;
  wait(0);
}
