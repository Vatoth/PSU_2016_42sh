/*
** my_calloc.c for my_calloc in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 17 13:26:40 2017 Léandre Blanchard
** Last update Wed May 17 13:51:21 2017 Léandre Blanchard
*/

#include <stdlib.h>

char		*my_calloc(int size)
{
  int       	i;
  char		*s;

  i = 0;
  if ((s = malloc(size)) == NULL)
    return (NULL);
  while (i != size)
    s[i++] = 0;
  return (s);
}
