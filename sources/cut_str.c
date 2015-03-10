/*
** cut_str.c for minishell2 in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 11 11:47:00 2015 Antoine Zanardi
** Last update Sat Feb 14 23:40:30 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

char		*pick_after_eq(char *str)
{
  char		*dest;
  int		compt_str;
  int		compt_dest;

  compt_str = 0;
  compt_dest = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(str))) == NULL)
    my_putstr_error(1);
  while (str[compt_str] != '=')
    compt_str++;
  compt_str++;
  while (str[compt_str] != '\0')
    {
      dest[compt_dest] = str[compt_str];
      compt_str++;
      compt_dest++;
    }
  dest[compt_dest] = '\0';
  return (dest);
}
