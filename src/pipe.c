/*
** pipe.c for 42sh in /home/nikola/delivery/PSU_2016_42sh
**
** Made by
** Login   <nikola@epitech.net>
**
** Started on  Sat May 20 17:47:08 2017
** Last update Sat May 20 23:30:48 2017 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

static int	left_pipe(t_btree *tmp, t_env *my_env,
			  int fd, t_list_al *alias)
{
  if (pipe(tmp->pp) == -1)
    return (0);
  if ((is_pipable(tmp->cmd)
       || builtins(tmp->cmd, my_env, alias) == 0)
      && fork() == 0)
    {
      if (dup2(tmp->pp[1], 1) == -1)
	exit(my_env->ret);
      close(tmp->pp[0]);
      if (my_strstr(tmp->cmd, ">"))
	exit(my_error(NULL, "Ambiguous output redirect.\n", 1, fd));
      redirections(tmp->cmd);
      if (!builtins(tmp->cmd, my_env, alias))
	execution(tmp->cmd, my_env, fd, alias);
      exit(my_env->ret);
    }
  return (1);
}

static void	right_pipe(t_btree *tmp, t_env *my_env,
			   int fd, t_list_al *alias)
{
  if (dup2(tmp->pp[0], 0) == -1)
    exit(my_env->ret);
  close(tmp->pp[1]);
  if (tmp->parent->parent)
    {
      if (dup2(tmp->parent->pp[1], 1) == -1)
	exit(my_env->ret);
      close(tmp->parent->pp[0]);
    }
  if (my_strstr(tmp->parent->right->cmd, ">")
      && tmp->parent->parent)
    exit(my_error(NULL, "Ambiguous output redirect.\n", 1, fd));
  redirections(tmp->parent->right->cmd);
  if (!builtins(tmp->parent->right->cmd, my_env, alias))
    execution(tmp->parent->right->cmd, my_env, fd, alias);
  exit(my_env->ret);
}

static int	pipe_exec(t_btree *tmp, t_env *my_env,
			  int fd, t_list_al *alias)
{
  if (tmp->cmd)
    {
      if (!left_pipe(tmp, my_env, fd, alias))
	return (0);
    }
  if (tmp->parent)
    {
      if (pipe(tmp->parent->pp) == -1)
	return (0);
    }
  if (tmp && tmp->parent && tmp->parent->right
      && tmp->parent->right->cmd
      && (is_pipable(tmp->parent->right->cmd)
      || builtins(tmp->parent->right->cmd, my_env, alias) == 0)
      && fork() == 0)
    right_pipe(tmp, my_env, fd, alias);
  if (tmp->pp)
    {
      close(tmp->pp[0]);
      close(tmp->pp[1]);
    }
  return (1);
}

static int	pipe_loop(t_btree *tree, t_env *my_env,
			  int fd, t_list_al *alias)
{
  t_btree	*tmp;

  tmp = get_outermost(tree, LEFT);
  while (tmp && tmp->parent)
    {
      if (!pipe_exec(tmp, my_env, fd, alias))
	return (my_env->ret = 1);
      tmp = tmp->parent;
    }
  return (0);
}

int		my_pipes(char *cmd, t_env *my_env, t_list_al *alias)
{
  t_btree	*tree;
  char		**tab;
  int		len;
  int		worst_status;
  int		fd;

  if (!cmd || !my_env || !(tab = my_str_to_wordtab(cmd, "|"))
      || (fd = dup(1)) == -1 || !check_cmds(tab, &(my_env->ret), cmd)
      || !(tree = make_tree(tab)))
    return (1);
  len = tab_len(tab) + 1;
  if (pipe_loop(tree, my_env, fd, alias) == 1)
    return (my_env->ret = 1);
  worst_status = 0;
  while (--len)
    {
      check_status(&(my_env->ret));
      worst_status = (my_env->ret) ? my_env->ret : worst_status;
    }
  free_tree(tree);
  free_tab(tab);
  close(fd);
  return ((my_env->ret = worst_status));
}
