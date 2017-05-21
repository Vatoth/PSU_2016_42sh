/*
** key.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May 19 16:58:25 2017 Léandre Blanchard
** Last update Sat May 20 15:16:28 2017 Léandre Blanchard
*/

#include "routine.h"

int                     up_key(t_curset *curset)
{
  static char           keys[3] = "\0\0\0";

  if (curset->cmds[0] == NULL)
    {
      zeros(curset->s, my_strlen(curset->s));
      return (1);
    }
  keys[0] = keys[1];
  keys[1] = keys[2];
  keys[2] = curset->ch;
  if (keys[0] == 27 && keys[1] == '[' && keys[2] == 'A')
    {
      zeros(keys, 3);
      new_hist(curset, -1);
      curset->cur = my_strlen(curset->s);
      return (0);
    }
  return (1);
}

int                     down_key(t_curset *curset)
{
  static char           keys[3] = "\0\0\0";

  if (curset->cmds[0] == NULL)
    {
      zeros(curset->s, my_strlen(curset->s));
      return (1);
    }
  keys[0] = keys[1];
  keys[1] = keys[2];
  keys[2] = curset->ch;
  if (keys[0] == 27 && keys[1] == '[' && keys[2] == 'B')
    {
      if (curset->cmds[0] == NULL)
	return (1);
      zeros(keys, 3);
      new_hist(curset, 1);
      curset->cur = my_strlen(curset->s);
      return (0);
    }
  return (1);
}

int                     left_key(t_curset *curset)
{
  static char           keys[3] = "\0\0\0";

  keys[0] = keys[1];
  keys[1] = keys[2];
  keys[2] = curset->ch;
  if (keys[0] == 27 && keys[1] == '[' && keys[2] == 'D')
    {
      shift_right(curset->s, 1);
      zeros(keys, 3);
      curset->cur -= 2;
      if (curset->cur < 0)
	curset->cur = 0;
      return (0);
    }
  return (1);
}

int                     right_key(t_curset *curset)
{
  static char           keys[3] = "\0\0\0";

  keys[0] = keys[1];
  keys[1] = keys[2];
  keys[2] = curset->ch;
  if (keys[0] == 27 && keys[1] == '[' && keys[2] == 'C')
    {
      shift_right(curset->s, 1);
      zeros(keys, 3);
      return (0);
    }
  return (1);
}
