/*
** nb_of.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 18 19:52:14 2017 Léandre Blanchard
** Last update Thu May 18 19:52:25 2017 Léandre Blanchard
*/

#include <stdlib.h>

int      nb_of(const char *src, char cmp)
{
  int           i;
  int           nb;

  i = 0;
  nb = 0;
  if (src == NULL)
    return (-1);
  while (src[i] != 0)
    {
      if (src[i] == cmp)
	nb++;
      i++;
    }
  return (nb);
}
