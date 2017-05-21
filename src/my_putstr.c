/*
** my_putstr.c for task03 in /home/TomicNikola/CPool_Day04
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Thu Oct  6 08:42:15 2016 Nikola Tomic
** Last update Sun May 21 16:59:51 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"

void	my_putstr(const char *str)
{
  if (str == NULL)
    write(1, "*NULL", 5);
  else
    write(1, str, my_strlen(str));
}
