/*
** list_len.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Apr 04 15:31:03 2017 nikola.tomic@epitech.eu
** Last update Sun Apr 09 13:54:18 2017 nikola.tomic@epitech.eu
*/

#include "my.h"

int		list_len(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (tmp)
    {
      tmp = tmp->next;
      i += 1;
    }
  return (i);
}

int	tab_len(char **tab)
{
  int	i;

  if (!tab)
    return (-1);
  i = 0;
  while (tab[i])
    i += 1;
  return (i);
}
