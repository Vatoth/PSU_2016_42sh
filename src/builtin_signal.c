/*
** builtin_signal.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May 19 17:00:42 2017 Léandre Blanchard
** Last update Fri May 19 19:12:04 2017 Léandre Blanchard
*/

#include "routine.h"
#include "colors.h"

int                     ctrl_c(t_curset *curset)
{
  if (curset->ch == 3)
    {
      zeros(curset->s, my_strlen(curset->s));
      my_printf("\n");
      disp_prompt();
      return (0);
    }
  return (1);
}

int                     ctrl_d(t_curset *curset)
{
  if (curset->ch != 4)
    return (1);
  if (curset->s[0] == 0)
    {
      free(curset->s);
      curset->s = NULL;
      return (0);
    }
  return (1);
}

int                     ctrl_l(t_curset *curset)
{
  if (curset->ch != 12)
    return (-1);
  my_printf(CLEARTOP);
  return (0);
}

int                     alt_l(t_curset *curset)
{
  static char           prev;

  if (prev == 27 && curset->ch == 'l')
    {
      free(curset->s);
      my_printf("\b\b  \n");
      prev = 0;
      return (0);
    }
  prev = curset->ch;
  return (1);
}

int			ctrl_k(t_curset *curset)
{
  char			*to_clear;

  if (curset->ch == 11)
    {
      to_clear = curset->s + curset->cur;
      zeros(to_clear, my_strlen(to_clear));
      curset->cur = my_strlen(curset->s);
      return (0);
    }
  return (1);
}
