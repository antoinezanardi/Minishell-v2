/*
** my_strlen.c for my_strlen in /home/zanard_a/rendu/J4/ex3
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Oct  2 12:42:56 2014 Antoine Zanardi
** Last update Thu Mar  5 11:14:20 2015 Antoine Zanardi
*/

#include	"my.h"

unsigned int	my_strlen(char *str)
{
  unsigned int	o;

  o = 0;
  while (str[o] != '\0')
    o++;
  return (o);
}
