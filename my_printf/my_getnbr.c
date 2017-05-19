/*
** my_getnbr.c for my_get_nbr in /home/lblanchard/CPool_Day04
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct  6 21:31:09 2016 Leandre Blanchard
** Last update Mon Apr 10 01:07:43 2017 Léandre Blanchard
*/

#include "my.h"

int	my_getnbr(const char *str)
{
  int	var;
  int	inv;
  int	i;

  inv = 1;
  var = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while ((*str < 47 || *str > 58) && *str != 0)
    {
      str = str + 1;
      i = i + 1;
    }
  if (i > 0 && *(str - 1) == 45)
    inv = -1;
  while (*str != 0 && *str >= '0' && *str <= '9')
    {
      var = var * 10;
      var = var + *str - 48;
      str = str + 1;
    }
  var = var * inv;
  return (var);
}
