##
## Makefile for 102cipher in /home/raphael.goulmot/rendu/102cipher
##
## Made by Raphaël Goulmot
## Login   <raphael.goulmot@epitech.net>
##
## Started on  Tue Nov 29 15:57:16 2016 Raphaël Goulmot
## Last update Fri Apr  7 14:59:16 2017 Raphaël Goulmot
##

CC	=	gcc

SRC	=	src/utils/my_putstr_err.c	\
		src/utils/my_putchar.c		\
		src/utils/my_putstr.c		\
		src/utils/my_strlen.c		\
		src/utils/my_getnbr.c		\
		src/utils/my_put_nbr.c		\
		src/utils/my_is.c		\
		src/utils/my_cleaner.c		\
		src/utils/my_string.c		\
		src/utils/split.c		\
		src/utils/line.c		\
		src/core/multi_commands.c	\
		src/core/commands.c		\
		src/core/commands/exit.c	\
		src/core/commands/env.c		\
		src/core/commands/cd.c		\
		src/core/exec.c			\
		src/core/main.c			\
		include/line.h			\
		include/commands.h		\
		include/exec.h			\
		include/utils.h

OBJ	=	$(SRC:.c=.o)

TMP	=	$(OBJ:.h=.h~)

CFLAGS	=	-W -Wextra -Werror -Iinclude -g

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(TMP)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

run:
	./$(NAME)
