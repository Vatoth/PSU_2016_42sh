/*
** my_frealloc.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May 19 17:43:19 2017 Léandre Blanchard
** Last update Fri May 19 17:45:05 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include "my.h"

char                    *my_frealloc(char *str, int size)
{
  char                  *s;

  if ((s = my_calloc(my_strlen(str) + size)) == NULL)
    return (NULL);
  my_strcpy(s, str);
  free(str);
  return (s);
}

