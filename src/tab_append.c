/*
** tab_append.c for tab_append in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 14 20:03:11 2017 Léandre Blanchard
** Last update Thu May 18 21:25:00 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include "my.h"

char		**tab_append(char **tab, char *add)
{
  char		**new;
  int		i;

  i = 0;
  if ((new = malloc(sizeof(char *) * (my_tablen(tab) + 2))) == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      new[i] = tab[i];
      i++;
    }
  new[i] = add;
  new[i + 1] = NULL;
  if (tab != NULL)
    free(tab);
  return (new);
}
