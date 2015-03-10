/*
** my_put_nbr.c for my_put_nbr in /home/zanard_a/rendu/J3/ex7
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Oct  1 17:16:33 2014 Antoine Zanardi
** Last update Thu Mar  5 11:14:48 2015 Antoine Zanardi
*/

#include	"my.h"

void	my_put_nbr(int nb)
{
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + 48);
    }
  else if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(nb * -1);
    }
  else if (nb >= 0 && nb <= 9)
    my_putchar((char)nb + 48);
}
