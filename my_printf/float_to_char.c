/*
** float_to_char.c for float_to_char in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Nov  9 12:26:31 2016 Leandre Blanchard
** Last update Tue May  2 17:12:29 2017 Léandre Blanchard
*/

#include "my_printf.h"
#include "my.h"

unsigned long long     	ret_zeros(long long nb)
{
  while (nb % 10 == 0 && nb != 0)
    nb /= 10;
  return (nb);
}

void			my_put_float(float nbr)
{
  long long	integer;
  long long	floating;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  integer = (long long)nbr;
  nbr = nbr - integer;
  nbr *= 100000000;
  floating = (long long)nbr;
  floating = ret_zeros(floating);
  my_put_nbr(integer);
  my_putchar('.');
  my_put_nbr(floating);
}
