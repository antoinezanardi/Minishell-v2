/*
** my_putchar.c for my_putchar in /home/zanard_a/rendu/Librairie tempo
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Oct  7 12:41:55 2014 Antoine Zanardi
** Last update Thu Mar  5 11:13:58 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	"my.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}
