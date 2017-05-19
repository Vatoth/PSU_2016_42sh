/*
** my_putstr.c for task03 in /home/TomicNikola/CPool_Day04
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Thu Oct  6 08:42:15 2016 Nikola Tomic
** Last update Wed May 17 14:47:08 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  if (str == NULL)
    return (write(1, "*NULL", 5));
  return (write(1, str, my_strlen(str)));
}
