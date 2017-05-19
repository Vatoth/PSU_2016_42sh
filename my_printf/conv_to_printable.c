/*
** conv_to_printable.c for conv_to_printable in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 16:36:03 2016 Leandre Blanchard
** Last update Fri Feb 24 16:28:41 2017 Léandre Blanchard
*/

#include "my.h"
#include "my_printf.h"

void	conv_to_printable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 32 && str[i] <= 127)
	my_putchar(str[i]);
      else
	{
	  my_putchar('\\');
	  (str[i] <= 7) ? my_putstr("00") : i;
	  (str[i] > 7 && str[i] <= 64) ? my_putstr("0") : i;
	  my_put_nbr(dec_to_base(str[i], 8));
	}
      i = i + 1;
    }
}
