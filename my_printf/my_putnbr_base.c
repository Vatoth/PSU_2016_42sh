/*
** my_putnbr_base.c for my_putnbr_base in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Nov  9 11:32:20 2016 Leandre Blanchard
** Last update Sun Apr 30 17:16:24 2017 Léandre Blanchard
*/

#include "my_printf.h"

int     part_of_base(char c, char *base)
{
  long	i;

  i = 0;
  while (base[i] != 0)
    {
      if (c == base[i])
	return (0);
      i = i + 1;
    }
  return (84);
}

int	my_put_pointer(long long nbr)
{
  char	*base;
  char	*result;
  unsigned long long	i;
  unsigned long long	j;

  j = 0;
  i = nbr;
  if ((result = malloc(sizeof (char) * 100)) == NULL)
    return (-1);
  if ((base = my_strdup("0123456789abcedf")) == NULL)
    return (-1);
  while (i)
    {
      result[j] = base[i % 16];
      i = i / 16;
      j = j + 1;
    }
  my_putstr(my_revstr(result));
  return (0);
}

int    my_putnbr_base(long long nbr, char *base)
{
  unsigned long long	basex;
  unsigned long long     i;
  char			*result;
  unsigned long long     j;

  j = 0;
  i = nbr;
  basex = my_strlen(base);
  if ((result = malloc(sizeof (char) * 100)) == NULL)
    return (-1);
  while (i)
    {
      result[j] = base[i % basex];
      i = i / basex;
      j = j + 1;
    }
  while (nbr)
    {
      if (part_of_base(result[nbr], base) == 0)
	my_putchar(result[nbr]);
      nbr = nbr - 1;
    }
  if (part_of_base(result[nbr], base) == 0)
    my_putchar(result[nbr]);
  return (0);
}

void    my_nputnbr_base(long long nbr, char *base, int n)
{
  my_putnbr_base(nbr, base);
}
