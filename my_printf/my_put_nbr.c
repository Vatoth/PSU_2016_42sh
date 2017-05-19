/*
** my_put_nbr.c for my_put_nbr in /home/lblanchard/CPool_Day03
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Oct  5 20:59:45 2016 Leandre Blanchard
** Last update Sun Apr 30 17:17:49 2017 Léandre Blanchard
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * ( -1 );
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  modulo = (nb % 10);
	  nb = (nb - modulo) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + modulo);
	}
      else
	{
	  my_putchar(48 + nb % 10);
	}
    }
}
