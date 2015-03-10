/*
** my_getnbr.c for my_get.nbr in /home/zanard_a/rendu/J4/ex5
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Oct  2 17:08:14 2014 Antoine Zanardi
** Last update Thu Mar  5 11:13:53 2015 Antoine Zanardi
*/

#include	"my.h"

int		my_getnbr(char *str)
{
  int		i;
  int		nbr;
  int		b;

  i = 0;
  b = 1;
  while ((str[i] != '\0') && (str[i] == '+' || str[i] == '-'))
    {
      if (str[i] == '-')
	b = b * (-1);
      i = i + 1;
    }
  str = str + i;
  i = 0;
  nbr = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (str[i] - '0');
      i = i + 1;
    }
  nbr = nbr * b;
  return (nbr);
}
