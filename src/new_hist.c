/*
** new_hist.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 20 14:48:19 2017 Léandre Blanchard
** Last update Sun May 21 17:05:57 2017 Léandre Blanchard
*/

#include "routine.h"
#include "libmy.h"

void		new_hist(t_curset *curset, int dir)
{
  shift_right(curset->s, 1);
  while (curset->hist >= 0 && curset->hist < my_tablen(curset->cmds)
	 && strcmp(curset->s, curset->cmds[curset->hist]) == 0)
    curset->hist += dir;
  if (curset->hist < 0)
    curset->hist = 0;
  if (curset->hist < my_tablen(curset->cmds) && curset->hist >= 0)
    {
      free(curset->s);
      curset->s = my_strdup(curset->cmds[curset->hist]);
    }
  if (curset->hist >= my_tablen(curset->cmds))
    curset->hist = my_tablen(curset->cmds) - 1;
  if (curset->hist == my_tablen(curset->cmds))
      zeros(curset->s, my_strlen(curset->s));
}
