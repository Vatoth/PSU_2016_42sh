/*
** move_and_add.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 20 17:40:57 2017 Léandre Blanchard
** Last update Sat May 20 18:08:05 2017 Léandre Blanchard
*/

#include "routine.h"

void		move_and_add(char *s, int cur, char ch)
{
  int		i;

  i = my_strlen(s);
  while (i > cur)
    {
      s[i] = s[i - 1];
      i--;
    }
  s[cur] = ch;
}

void		move_and_ret(char *s, int cur)
{
  int		i;

  i = cur - 1;
  while (s[i] != 0)
    {
      s[i] = s[i + 1];
      i++;
    }
}
