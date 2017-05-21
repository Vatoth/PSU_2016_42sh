/*
** my_strcpy.c for task02 in /home/TomicNikola/CPool_Day06
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Mon Oct 10 08:12:01 2016 Nikola Tomic
** Last update Sat May 20 22:19:06 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include <string.h>

char	*my_strcpy(char *dest, const char *src)
{
  if (!src || !dest)
    return (NULL);
  strcpy(dest, src);
  return (dest);
}
