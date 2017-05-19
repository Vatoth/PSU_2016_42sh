/*
** my_int_char.c for int_char in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:14:41 2017 Léandre Blanchard
** Last update Wed May  3 14:31:26 2017 Léandre Blanchard
*/

#include "my.h"

char            *int_char(int nb)
{
  char          *str;
  int           i;
  int           ret;

  ret = 0;
  if (nb == 0)
    return (my_strdup("0"));
  if ((str = my_calloc(my_intlen(nb) + 1)) == NULL)
    return (NULL);
  i = 0;
  if (nb < 0)
    {
      nb = nb * -1;
      ret = 1;
    }
  while (nb != 0)
    {
      str[i] = (nb % 10) + 48;
      nb = nb / 10;
      i++;
    }
  if (ret == 1)
    str[i] = '-';
  return (my_revstr(str));
}

