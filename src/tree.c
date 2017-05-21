/*
** tree.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Sun Apr 09 11:33:57 2017 nikola.tomic@epitech.eu
** Last update Sat May 20 15:09:55 2017 
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

t_btree		*put_node(t_btree *parent, char *cmd, char side)
{
  t_btree	*node;

  if (!(node = (t_btree *) malloc(sizeof(*node))))
    return (NULL);
  node->cmd = my_strdup(cmd);
  node->parent = parent;
  node->left = NULL;
  node->right = NULL;
  if (!parent || side == LEFT)
    {
      if (!(node->pp = (int *) malloc(sizeof(int) * 2)))
	return (NULL);
    }
  if (parent && side == LEFT)
    parent->left = node;
  else if (parent)
    {
      parent->right = node;
      node->pp = parent->pp;
    }
  return (node);
}

t_btree		*get_outermost(t_btree *tree, char side)
{
  if (!tree)
    return (NULL);
  if (side == LEFT && tree->left)
    return (get_outermost(tree->left, LEFT));
  else if (side == RIGHT && tree->right)
    return (get_outermost(tree->right, RIGHT));
  else
    return (tree);
}

t_btree		*make_tree(char **tab)
{
  t_btree	*tree;
  t_btree	*leftmost;
  int		i;

  if (!tab)
    return (NULL);
  tree = put_node(NULL, NULL, RIGHT);
  i = tab_len(tab);
  while (--i > 0)
    {
      if (!(leftmost = get_outermost(tree, LEFT)) ||
	  !put_node(leftmost, tab[i], RIGHT))
	return (NULL);
      if (i > 1)
	{
	  if (!put_node(leftmost, NULL, LEFT))
	    return (NULL);
	}
    }
  if (!(leftmost = get_outermost(tree, LEFT)) ||
      !put_node(leftmost, tab[0], LEFT))
    return (NULL);
  return (tree);
}
