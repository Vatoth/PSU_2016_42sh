/*
** put.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 18 21:25:51 2017 Léandre Blanchard
** Last update Thu May 18 21:26:46 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include "my.h"

void            my_put_tab(char **tab)
{
  int           i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	my_printf("%s\n", tab[i++]);
    }
}

void            my_put_tabw(const char *start, char **tab, const char *end)
{
  int           i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	my_printf("%s%s%s", start, tab[i++], end);
    }
}
