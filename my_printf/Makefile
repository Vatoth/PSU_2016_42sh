##
## Makefile for Makefile in /home/TomicNikola/CPool_rush2
##
## Made by Nikola Tomic
## Login   <TomicNikola@epitech.net>
##
## Started on  Sat Oct 15 19:37:46 2016 Nikola Tomic
## Last update Sun May 21 18:20:38 2017 
##

CFLAGS	+= -Wall -Wextra -Werror

SRC 	= char_to_nchar.c \
	  char_to_nchar.c \
	  int_to_char.c \
	  my_putstr.c \
	  pointeur.c \
	  conv_to_printable.c \
	  int_to_nint.c \
	  my_int_char.c \
	  my_putchar.c \
	  my_putstr_error.c \
	  dec_to_base.c \
	  my_int_len.c \
	  my_putnbr_base.c \
	  my_strncpy.c \
	  float_to_char.c \
	  my_getnbr.c \
	  my_printf.c \
	  my_put_nbr.c \
	  nb_arg.c


OBJ	= $(SRC:.c=.o)

NAME	= libmyprintf.a

RM	= -rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
