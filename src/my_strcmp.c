/*
** my_strcmp.c for task06 in /home/TomicNikola/CPool_Day06
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Mon Oct 10 12:44:53 2016 Nikola Tomic
** Last update Tue May 16 16:46:35 2017 Léandre Blanchard
*/

#include <string.h>
#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return (-1);
  return (strcmp(s1, s2));
}
