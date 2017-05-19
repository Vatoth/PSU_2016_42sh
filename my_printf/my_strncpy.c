/*
** my_strncpy.c for my_strncpy in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Fri Oct  7 11:01:26 2016 Leandre Blanchard
** Last update Mon Apr 10 01:07:57 2017 Léandre Blanchard
*/

#include <stdlib.h>

char	*my_strncpy(char *dest, const char *src, int n)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (n > 0 && *(src + i))
    {
      *(dest + i) = *(src + i);
      i = i + 1;
      n = n - 1;
    }
  if (n > 0)
    *(dest + i) = ('\0');
  return (dest);
}
