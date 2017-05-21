/*
** my_strdup.c for task01 in /home/TomicNikola/CPool_Day08/task01
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Wed Oct 12 12:42:42 2016 Nikola Tomic
** Last update Sat May 20 22:19:44 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(const char *src)
{
  char	*dest;
  int	len;

  len = my_strlen(src);
  if (src == NULL)
    return (NULL);
  if ((dest = my_calloc(len + 1)) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
