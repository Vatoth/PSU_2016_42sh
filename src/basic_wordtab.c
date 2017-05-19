/*
** basic_wordtab.c for wordtab in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 18 21:33:54 2017 Léandre Blanchard
** Last update Fri May 19 09:49:28 2017 Léandre Blanchard
*/

#include "42sh_history.h"

static int	count_words(const char *str, int separator)
{
  int           i;
  int           nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      while (str[i] && str[i] != separator)
	i++;
      nb++;
      while (str[i] && str[i] == separator)
	i++;
    }
  nb++;
  return (nb);
}

char		**basic_wordtab(const char *str, int s)
{
  t_tab         tab;

  tab.i = 0;
  tab.y = 0;
  tab.k = 0;
  if ((tab.array = malloc(sizeof(*tab.array) * count_words(str, s))) == NULL)
    return (NULL);
  tab.nb = 0;
  while (str[tab.i])
    {
      tab.nb = tab.i;
      while (str[tab.nb] && str[tab.nb] != s && str[tab.nb])
	tab.nb++;
      if ((tab.array[tab.k] = malloc(sizeof(tab.array) * tab.nb)) == NULL)
	return (NULL);
      tab.nb = 0;
      tab.y = 0;
      while (str[tab.i] && str[tab.i] != s)
	tab.array[tab.k][tab.y++] = str[tab.i++];
      tab.array[tab.k++][tab.y] = '\0';
      while (str[tab.i] && str[tab.i] == s)
	tab.i++;
    }
  tab.array[tab.k] = NULL;
  return (tab.array);
}
