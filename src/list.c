/*
** display_list.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Apr 04 12:40:31 2017 nikola.tomic@epitech.eu
** Last update Mon May 15 23:43:09 2017 
*/

#include <stdlib.h>
#include "my.h"

void		display_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      my_putstr(tmp->var);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int		remove_node(t_list **list, t_list *node)
{
  t_list	*tmp;

  if (*list == node)
    {
      *list = (*list)->next;
      return (1);
    }
  tmp = *list;
  while (tmp && tmp->next != node)
    tmp = tmp->next;
  if (!tmp)
    return (0);
  tmp->next = node->next;
  if (node)
    free(node);
  return (1);
}

t_list		*put_in_list(t_list **list, char *var)
{
  t_list	*node;
  t_list	*tmp;

  if (!var || !list || !(node = (t_list *) malloc(sizeof(*node))) ||
      !(node->var = my_strdup(var)))
    return (NULL);
  node->next = NULL;
  if (!(*list))
    *list = node;
  else
    {
      tmp = *list;
      while (tmp && tmp->next)
	tmp = tmp->next;
      tmp->next = node;
    }
  return (node);
}

t_list		*tab_to_list(char **tab)
{
  t_list	*list;
  int		i;

  if (!tab)
    return (NULL);
  list = NULL;
  i = 0;
  while (tab[i])
    {
      put_in_list(&list, tab[i]);
      i += 1;
    }
  return (list);
}

char		**list_to_tab(t_list *list)
{
  t_list	*tmp;
  char		**tab;
  int		i;

  if (!list || !(tab = malloc(sizeof(char *) * (list_len(list) + 1))))
    return (NULL);
  tmp = list;
  i = 0;
  while (tmp)
    {
      if (!(tab[i] = my_strdup(tmp->var)))
	return (NULL);
      tmp = tmp->next;
      i += 1;
    }
  tab[i] = NULL;
  return (tab);
}
