/*
** minishell.h for minishell in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minishell1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Jan 12 15:43:26 2015 Antoine Zanardi
** Last update Sun Mar  8 13:48:21 2015 Antoine Zanardi
*/

#ifndef			MINISHELL_H_
# define		MINISHELL_H_

typedef	struct		s_list
{
  char			*str;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef	struct		s_tabline
{
  int			word;
  int			letters;
}			t_tabline;

typedef	struct		s_command
{
  char			**tab;
  int			type;
  struct s_command	*next;
  struct s_command	*prev;
}			t_command;

void			my_show_list(t_list *);
void			add_env_to_list(char **, t_list **);
void		        my_show_tab(char **);
void			line_to_tab(t_command **, char *, int *, int);
void			pass_spaces(char *, int *);
void			pass_the_slash(char *, int *);
void			apply_pwd(t_list **, char *, char *);
void			ta_list(char **, char *, int, t_command **);
void			choose_type(t_command **, char **, t_list **);
void			no_command(char *);
void			my_command(char **, char **, t_list **);
void			my_cd(char **, t_list **);
void			pipe_mult(t_command **, char **, t_list **);
void			redir_sr(t_command **, char **, t_list **);
void			redir_dr(t_command **, char **, t_list **);
void			write_file_dr(int *, char *);
void			redir_sl(t_command **, char **, t_list **);
void			redir_sl_son(int *, t_command *, char *, char **);
void			treat_exit(char **);
void			home_cd(t_list **, char **);
void			compt_pipe(t_command *, int *);
void			remove_elem_list(t_list *, t_list **);
void			init_current_pwd(t_list **, char *, int *, int *);
void			treat_current_pwd(int *, int *, char *);
void			treat_direct_pwd(char *, int *, char *, int *);
void			write_file_sr(int *, char *);
void			my_exit(char *, int);
void			output_command(char **, char **, t_list **);
void			check_fork_error(int *, int *);
void			signal_c(int);
char			*get_my_folder(char *, int *);
char			*change_direct_pwd(char *, t_list **);
char			*change_current_pwd(char *, t_list **);
char			*pick_after_eq(char *);
char			*my_str_paste(char *, char *);
char			*path_comm(char **, char *);
char			*pwd_paste(char *, char *);
char			*swap_pwds(t_list **);
char			*get_my_oldpwd(t_list **);
char			*get_my_pwd(t_list **);
char			*only_pwd(char *);
char			*only_eq(char *);
char			*only_var_unset(char *);
char			*pick_path_line(t_list **, int *, int *);
char			**path_to_tab(t_list **, char **);
char			**list_to_wordtab(t_list **);
char			*path_command(char **, char *);
int			father_pipe(t_command *, int *, char *, char **);
int			recur_pipe(t_command *, t_list **, char **);
int			my_shell(char **, char **);
int			redir_sr_son(int *, char *, char **, char **);
int			prompt(t_list **);
int			command_top_list(char **, t_command **, int);
int			command_bot_list(char **, t_command **, int);
int			parse_end(char *);
int			parse_begin(char *);
int			parse_multiple(char *);
int			parse_redirection(char *);
int			str_is_nbr(char *);
int			len_pwd(char *);
int			my_putstr_error(int);
int			len_eq(char *);
int			len_unset(char *);
int			nb_var(t_list **);
int			line_to_list(char *, t_command **);
int			parse_unsetenv(char *);
int			parse_setenv(char *);
int			parse_eq(char *);
int			find_double_slash(char *);
int			redir_sr_son(int *, char *, char **, char **);
int			check_pipe_fork(int *, int *);
int			parse_pwd(char *);
int			my_set_env(t_list **, char **);
int			my_unset_env(t_list **, char **);
int			my_set_envpwd(t_list **, char *);
int			find_command(char *, char **);
int			parse_consecutive(char *);
int			parse_line(char *);
int			parsing_list(t_command **);
int			add_bot_list(t_list **, char *);
int			add_top_list(t_list **, char *);
int			my_strcmp(char *, char *, int);
int			my_strcmp_exact(char *, char *, int);
int			default_prompt(int *);
int			display_prompt(char *, int *);
unsigned int		nb_command(char *, int);
unsigned int		let_com(char *, int);
unsigned int		nb_path(char *);
unsigned int		nb_let(char *, int);

#endif			/* !MINISHELL_H_ */
