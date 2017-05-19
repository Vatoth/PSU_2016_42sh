/*
** my_catalloc.c for my_catalloc in /home/leandre/System_unix/PSU_2016_minishell2
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Apr  3 19:27:11 2017 Léandre Blanchard
** Last update Thu May 18 20:57:19 2017 Léandre Blanchard
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

static int	len_s(const char *s)
{
  int		i;

  i = 0;
  if (s == NULL)
    return (0);
  while (s[i] != 0)
    i++;
  return (i);
}

char		*my_catalloc(const char *s, const char *s_2, const char *s_3)
{
  char		*out;
  int		len;

  len = len_s(s) + len_s(s_2) + len_s(s_3);
  if (len == 0)
    return (NULL);
  if ((out = malloc(len + 1)) == NULL)
    return (NULL);
  memset(out, 0, len + 1);
  if (s != NULL)
    strcat(out, s);
  if (s_2 != NULL)
    strcat(out, s_2);
  if (s_3 != NULL)
    strcat(out, s_3);
  return (out);
}
