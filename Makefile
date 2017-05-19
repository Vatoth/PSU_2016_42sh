##
## Makefile for Makefile in /home/TomicNikola/CPool_rush2
##
## Made by Nikola Tomic
## Login   <TomicNikola@epitech.net>
##
## Started on  Sat Oct 15 19:37:46 2016 Nikola Tomic
## Last update Fri May 19 22:49:30 2017 
##

CPPFLAGS	+= -I./include/ -g -g3

LIB	= -L./my_printf -lmyprintf -lncurses

CFLAGS	+= -Wall -Wextra

SRC	= src/builtins.c		\
	  src/find_path.c		\
	  src/free.c			\
	  src/alias.c			\
	  src/tab_append.c		\
	  src/builtin_signal.c		\
	  src/cursor.c			\
	  src/put_space.c		\
	  src/basic_wordtab.c		\
	  src/my_frealloc.c		\
	  src/key.c			\
	  src/parse.c			\
	  src/add_color.c		\
	  src/via_pipe.c		\
	  src/routine_ioctl.c		\
	  src/nb_of.c			\
	  src/list.c			\
	  src/clear_line.c		\
	  src/tools.c			\
	  src/my_putchar.c		\
	  src/my_putstr.c		\
	  src/my_str_to_wordtab.c	\
	  src/put.c			\
	  src/my_strcat.c		\
	  src/my_strcmp.c		\
	  src/my_strlen.c		\
	  src/exec.c			\
	  src/my_strncmp.c		\
	  src/my_strstr.c		\
	  src/my_strdup.c		\
	  src/my_strcpy.c		\
	  src/len.c			\
	  src/get_next_line.c		\
	  src/my_str_isalnum.c		\
	  src/signal.c			\
	  src/my_isalnum.c		\
	  src/tree.c			\
	  src/redirections.c		\
	  src/prompt.c			\
	  src/shift.c			\
	  src/my_catalloc.c		\
	  src/my_revstr.c		\
	  src/shell.c			\
	  src/clear.c			\
	  src/echo.c			\
	  src/my_calloc.c		\
	  src/42sh_history.c		\
	  src/main.c

OBJ	= $(SRC:.c=.o)

NAME	= 42sh

CC	= gcc

RM	= -rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
