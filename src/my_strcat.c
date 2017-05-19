/*
** my_strcat.c for task02 in /home/TomicNikola/CPool_Day07
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Tue Oct 11 15:01:58 2016 Nikola Tomic
** Last update Tue Apr 04 15:35:07 2017 nikola.tomic@epitech.eu
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  char	*ret;
  int	i;
  int	y;

  if (!dest || !src)
    return ((dest) ? my_strdup(dest) : (src) ? my_strdup(src) : NULL);
  if (!(ret = malloc(my_strlen(dest) + my_strlen(src) + 1)))
    return (NULL);
  i = 0;
  while (dest[i] != 0)
    {
      ret[i] = dest[i];
      i += 1;
    }
  y = 0;
  while (src[y] != 0)
    {
      ret[i] = src[y];
      i += 1;
      y += 1;
    }
  ret[i] = 0;
  return (ret);
}
