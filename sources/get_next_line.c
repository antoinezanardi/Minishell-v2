/*
** get_next_line.c for get_next_line in /home/zanard_a/rendu/Projets_TEK1/Brouillon/getnextline
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Nov 21 17:36:32 2014 Antoine Zanardi
** Last update Thu Mar  5 11:01:23 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"./get_next_line.h"

unsigned int	my_len(char *str)
{
  unsigned int	compt;

  compt = 0;
  if (str == NULL)
    return (0);
  while (str[compt] != '\0')
    compt++;
  return (compt);
}

char	*str_paste(char *str, char *buff)
{
  int	compt_des;
  int	compt_buffer;
  char	*str_des;

  compt_buffer = 0;
  compt_des = 0;
  if ((str_des = malloc(sizeof(char) * (my_len(str) +
					my_len(buff) + 1))) == NULL)
    return (NULL);
  if (buff != NULL)
    {
      while (buff[compt_buffer] != '\0')
	str_des[compt_des++] = buff[compt_buffer++];
      free(buff);
    }
  compt_buffer = 0;
  if (str != NULL)
    {
      while (str[compt_buffer] != '\0')
	str_des[compt_des++] = str[compt_buffer++];
      free(str);
    }
  str_des[compt_des] = '\0';
  return (str_des);
}

int	check_my_entry(char *buffer, int buffer_compt)
{
  if (buffer == NULL)
    return (0);
  while (buffer[buffer_compt] != '\0')
    {
      if (buffer[buffer_compt] == '\n' || buffer[buffer_compt] == '\0')
	return (1);
      else
	buffer_compt++;
    }
  return (0);
}

char		*result(char *buffer, int *buffer_compt, char *str)
{
  int	str_compt;

  str_compt = 0;
  while (buffer[*buffer_compt] != '\n' && buffer[*buffer_compt] != '\0')
    {
      str[str_compt] = buffer[*buffer_compt];
      str_compt++;
      *buffer_compt = *buffer_compt + 1;
    }
  str[str_compt] = '\0';
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	*buffer;
  static int	buffer_compt = 0;
  char		*str_tmp;
  char		*str;
  int		bool;
  long		ret;

  if (buffer != NULL && buffer[buffer_compt] == '\0')
    return (NULL);
  else if (buffer != NULL && buffer[buffer_compt] == '\n')
    buffer_compt++;
  bool = check_my_entry(buffer, buffer_compt);
  while (bool == 0)
    {
      if ((str_tmp = malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
	return (NULL);
      if (((ret = read(fd, str_tmp, BUFFER_SIZE))) == 0)
	  bool = 1;
      str_tmp[ret] = '\0';
      buffer = str_paste(str_tmp, buffer);
      bool = check_my_entry(buffer, buffer_compt) || bool;
    }
  if ((str = malloc(sizeof(char) * my_len(buffer) + 1)) == NULL)
    return (NULL);
  return (result(buffer, &buffer_compt, str));
}
