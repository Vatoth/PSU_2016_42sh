/*
** my_strdup.c for task01 in /home/TomicNikola/CPool_Day08/task01
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Wed Oct 12 12:42:42 2016 Nikola Tomic
** Last update Tue Apr 04 15:35:19 2017 nikola.tomic@epitech.eu
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*dest;

  if (!src ||
      (dest = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
