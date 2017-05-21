/*
** my_strlen.c for task04 in /home/TomicNikola/CPool_Day04
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Thu Oct  6 09:06:37 2016 Nikola Tomic
** Last update Sat May 20 22:16:21 2017 Léandre Blanchard
*/

#include <stdlib.h>

int	my_strlen(const char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
