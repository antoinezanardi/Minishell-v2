/*
** fc.c for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 11 11:40:03 2015 Antoine Zanardi
** Last update Thu Mar  5 10:42:13 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"minishell.h"
#include	"my.h"

char		*my_str_paste(char *str1, char *str2)
{
  char		*dest;
  int		compt_str;
  int		compt_str2;

  if ((dest = malloc(sizeof(char) *
		     (unsigned int)(my_strlen(str1) + my_strlen(str2)
				    + 2))) == NULL)
    return (NULL);;
  compt_str = 0;
  compt_str2 = 0;
  while (str1[compt_str] != '\0')
    {
      dest[compt_str] = str1[compt_str];
      compt_str++;
    }
  dest[compt_str] = '/';
  compt_str++;
  while (str2[compt_str2] != '\0')
    {
      dest[compt_str] = str2[compt_str2];
      compt_str2++;
      compt_str++;
    }
  dest[compt_str] = '\0';
  return (dest);
}

int		my_strcmp_exact(char *str, char *str2, int compt2)
{
  int		compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      if (str2[compt2] == '\0' || str[compt] != str2[compt2])
	return (1);
      else
	{
	  compt++;
	  compt2++;
	}
    }
  if (str[compt] != '\0' || str2[compt2] != '\0')
    return (1);
  return (0);
}

int		my_strcmp(char *str, char *str2, int compt2)
{
  int		compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      if (str2[compt2] == '\0' || str[compt] != str2[compt2])
	return (1);
      else
	{
	  compt++;
	  compt2++;
	}
    }
  return (0);
}

void		pass_spaces(char *str, int *compt_str)
{
  while ((str[*compt_str] == ' ' || str[*compt_str] == '\t') &&
	 str[*compt_str] != '\0')
    (*compt_str)++;
}
