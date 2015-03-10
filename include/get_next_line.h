/*
** get_next_line.h for get_next_line in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_get_next_line
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Nov 17 11:52:13 2014 Antoine Zanardi
** Last update Thu Mar  5 11:01:03 2015 Antoine Zanardi
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_
# define	BUFFER_SIZE	4096

typedef struct	s_struct
{
  char		*str_tmp;
  char		*str;
  int		str_compt;
  int		bool;
  int		ret;
}		t_str;

char		*get_next_line(const int);
char		*str_paste(char *, char *);
char		*result(char *, int *, char *);
int		check_my_entry(char *, int);
unsigned int	my_len(char *);

#endif /* !GET_NEXT_LINE_H_ */
