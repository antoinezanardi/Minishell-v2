/*
** error.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 13 11:56:19 2015 Antoine Zanardi
** Last update Thu Mar  5 13:41:33 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

int		my_putstr_error(int error)
{
  if (error == 1)
    my_putstr("Malloc Failed, program will exit\n");
  else if (error == 2)
    my_putstr("A pipe failed, program will exit\n");
  else if (error == 3)
    my_putstr("A fork failed, program will exit\n");
  else if (error == 4)
    my_putstr("A dup didn't went well, program will exit\n");
  exit(1);
}
