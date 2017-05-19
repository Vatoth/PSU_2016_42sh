/*
** cursor.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May 19 17:04:08 2017 Léandre Blanchard
** Last update Fri May 19 17:40:55 2017 Léandre Blanchard
*/

#include "routine.h"

void                    backspace(char *s)
{
  int                   i;

  i = 0;
  while (i < my_strlen(s) + 10)
    {
      write(1, " ", 1);
      i++;
    }
  while (i != 0)
    {
      write(1, "\b", 1);
      i--;
    }
}

int                     ret_back(t_curset *curset)
{
  if (curset->ch != 127)
    return (1);
  if (my_strlen(curset->s) < 1)
    return (1);
  curset->s[my_strlen(curset->s) - 1] = 0;
  curset->cur = curset->cur - 1;
  return (0);
}

int                     cur_end(t_curset *curset)
{
  static char           keys[3] = "\0\0\0";

  keys[0] = keys[1];
  keys[1] = keys[2];
  keys[2] = curset->ch;
  if (keys[0] == 27 && keys[1] == 'O' && keys[2] == 'F')
    {
      shift_right(curset->s, 1);
      zeros(keys, 3);
      curset->cur = my_strlen(curset->s);
      return (0);
    }
  return (1);
}

int                     cur_home(t_curset *curset)
{
  static char           keys[3] = "\0\0\0";

  keys[0] = keys[1];
  keys[1] = keys[2];
  keys[2] = curset->ch;
  if (keys[0] == 27 && keys[1] == 'O' && keys[2] == 'H')
    {
      shift_right(curset->s, 1);
      zeros(keys, 3);
      curset->cur = 0;
      return (0);
    }
  return (1);
}

void                    print_cur(int cur, char *s)
{
  int                   i;

  my_printf("\r");
  disp_prompt();
  backspace(s);
  my_printf("%s", s);
  i = my_strlen(s);
  while (i > 0)
    {
      my_printf("\b");
      i--;
    }
  while (i < cur)
    {
      my_printf("%c", s[i]);
      i++;
    }
}
