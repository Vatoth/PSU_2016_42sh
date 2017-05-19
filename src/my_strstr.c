/*
** my_strstr.c for task05 in /home/TomicNikola/CPool_Day06
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Mon Oct 10 12:21:37 2016 Nikola Tomic
** Last update Tue Apr 04 15:35:28 2017 nikola.tomic@epitech.eu
*/

#include <stdlib.h>
#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	y;
  int	j;

  if (!str || !to_find || my_strlen(str) < my_strlen(to_find))
    return (NULL);
  i = 0;
  while (str[i] != 0)
    {
      y = 0;
      j = 0;
      while (to_find[y] != 0)
	{
	  if (str[i + y] == 0)
	    return (NULL);
	  j = (str[i + y] == to_find[y]);
	  y += 1;
	}
      if (j == 1)
	return (&str[i]);
      i += 1;
    }
  return (NULL);
}
