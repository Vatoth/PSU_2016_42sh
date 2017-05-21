##
## Makefile for Makefile in /home/TomicNikola/CPool_rush2
##
## Made by Nikola Tomic
## Login   <TomicNikola@epitech.net>
##
## Started on  Sat Oct 15 19:37:46 2016 Nikola Tomic
## Last update Sun May 21 20:32:16 2017 
##

CPPFLAGS	+= -I./include/

LIBS	= -L./my_printf -lmyprintf -lncurses

LIB	= my_printf/libmyprintf.a

CFLAGS	+= -Wall -Wextra -Werror

SRC_LIB = my_printf/char_to_nchar.c \
          my_printf/char_to_nchar.c \
          my_printf/int_to_char.c \
          my_printf/my_putstr.c \
          my_printf/pointeur.c \
          my_printf/conv_to_printable.c \
          my_printf/int_to_nint.c \
          my_printf/my_int_char.c \
          my_printf/my_putchar.c \
          my_printf/my_putstr_error.c \
          my_printf/dec_to_base.c \
          my_printf/my_int_len.c \
          my_printf/my_putnbr_base.c \
          my_printf/my_strncpy.c \
          my_printf/float_to_char.c \
          my_printf/my_getnbr.c \
          my_printf/my_printf.c \
          my_printf/my_put_nbr.c \
          my_printf/nb_arg.c

OBJ_LIB =  $(SRC_LIB:.c=.o)

SRC	= src/builtins.c		\
	  src/find_path.c		\
	  src/alias.c			\
	  src/init_alias.c		\
	  src/free.c			\
	  src/init_execution.c	 	\
	  src/move_and_add.c		\
	  src/complete.c		\
	  src/loop_cmd.c		\
	  src/tab_append.c		\
	  src/builtin_signal.c		\
	  src/my_str_isascii.c		\
	  src/call_completion.c		\
	  src/new_hist.c		\
	  src/get_path.c		\
	  src/cursor.c			\
	  src/put_space.c		\
	  src/basic_wordtab.c		\
	  src/my_frealloc.c		\
	  src/key.c			\
	  src/parse2.c			\
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
	  src/fullfill_echo.c		\
	  src/my_calloc.c		\
	  src/42sh_history.c		\
	  src/more_tools.c		\
	  src/pipe.c			\
	  src/main.c

OBJ	= $(SRC:.c=.o)

NAME	= 42sh

CC	= gcc

RM	= -rm -f

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

$(LIB): $(OBJ_LIB)
	ar rc ./my_printf/libmyprintf.a $(OBJ_LIB)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_LIB)

fclean: clean
	$(RM) $(NAME)
	$(RM) ./my_printf/libmyprintf.a

re: fclean all

.PHONY: all clean fclean re
