/*
** clear.c for clear in /home/leandre/Rushs/scroller
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr  2 22:15:29 2017 Léandre Blanchard
** Last update Sun May 21 15:21:17 2017 
*/

#include <ncurses.h>
#include "my.h"

int		term_width(void)
{
  return (COLS);
}

void		my_clear(void)
{
  int		i;
  int		size;

  i = 0;
  size = term_width();
  while (i != size)
    {
      my_printf(" ");
      i++;
    }
}
