##
## Makefile for make in /home/zanard_a/rendu/Projets Piscines/expr
##
## Made by Antoine Zanardi
## Login   <zanard_a@epitech.net>
##
## Started on  Tue Oct 21 16:47:57 2014 Antoine Zanardi
## Last update Fri Mar  6 16:03:15 2015 Antoine Zanardi
##

DEBUG	=	no

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g -Wall -Wextra
endif

ifeq ($(CC), clang)
CFLAGS	=	-Weverything -Wno-padded
endif


SRCS_PA =	./sources/

LIB_PA	=	./lib/my/

NAME	=	mysh

SRCS_PA =	sources/

SRCS	=	$(SRCS_PA)main.c \
		$(SRCS_PA)minishell.c \
		$(SRCS_PA)access_command.c \
		$(SRCS_PA)pipe.c \
		$(SRCS_PA)redir_sr.c \
		$(SRCS_PA)redir_dr.c \
		$(SRCS_PA)redir_sl.c \
		$(SRCS_PA)env.c \
		$(SRCS_PA)get_next_line.c \
		$(SRCS_PA)prompt.c \
		$(SRCS_PA)cut_str.c \
		$(SRCS_PA)path.c \
		$(SRCS_PA)line_to_tab.c \
		$(SRCS_PA)list_command.c \
		$(SRCS_PA)list_to_wordtab.c \
		$(SRCS_PA)fc.c \
		$(SRCS_PA)parse_line.c \
		$(SRCS_PA)parse_the_list.c \
		$(SRCS_PA)parse_redir.c \
		$(SRCS_PA)error.c \
		$(SRCS_PA)my_exit.c \
		$(SRCS_PA)home_cd.c \
		$(SRCS_PA)pwd.c \
		$(SRCS_PA)change_direct_pwd.c \
		$(SRCS_PA)change_current_pwd.c \
		$(SRCS_PA)my_cd.c \
		$(SRCS_PA)setenv.c \
		$(SRCS_PA)signal.c \
		$(SRCS_PA)unset_env.c \

SRCS_LI	=	$(LIB_PA)my_getnbr.c \
		$(LIB_PA)my_putchar.c \
		$(LIB_PA)my_put_nbr.c \
		$(LIB_PA)my_putstr.c \
		$(LIB_PA)my_strlen.c \
		$(LIB_PA)my_lists.c \

OBJS	=	$(SRCS:.c=.o)

OBJS_LI	=	$(SRCS_LI:.c=.o)

INC	=	-I include/

LIB_CMP	=	$(LIB_PA)libmy.a

CFLAGS	+=	$(INC)


all: $(LIB_CMP) $(NAME)

$(LIB_CMP): $(OBJS_LI)
	ar rc $(LIB_CMP) $(OBJS_LI)
	ranlib $(LIB_CMP)
	cp $(LIB_PA)my.h ./include/

$(NAME): $(OBJS)
	cc -Wall $(OBJS) lib/my/libmy.a $(MLX) $(INC) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_LI)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_CMP)

re: fclean all

.PHONY: all clean fclean all
