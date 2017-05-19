/*
** int_to_char.c for int_to_char in /home/lblanchard/PSU_2016_my_printf/lib/my
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 19:24:05 2016 Leandre Blanchard
** Last update Sun Apr 30 16:46:10 2017 Léandre Blanchard
*/

#include "my.h"

char    *int_to_char(int nb)
{
  char  *number;
  int   nm;
  int   len;
  int   i;

  i = 0;
  len = 0;
  nm = nb;
  while (nm / 10 != 0)
    {
      len = len + 1;
      nm = nm / 10;
    }
  number = malloc(sizeof (char) * i + 1);
  i = 0;
  while (nb % 10 != 0)
    {
      number[i] = nb % 10 + 48;
      nb = nb / 10;
      i = i + 1;
    }
  return (my_revstr(number));
}
