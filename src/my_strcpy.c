/*
** my_strcpy.c for task02 in /home/TomicNikola/CPool_Day06
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Mon Oct 10 08:12:01 2016 Nikola Tomic
** Last update Wed Mar 01 23:44:13 2017 nikola.tomic@epitech.eu
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
  int	inc;

  inc = 0;
  if (!src || !dest)
    return (NULL);
  while (src[inc] != '\0')
    {
      dest[inc] = src[inc];
      inc = inc + 1;
    }
  dest[inc] = '\0';
  return (dest);
}
