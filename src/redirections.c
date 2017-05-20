/*
** redirections.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Sat Apr 08 13:26:38 2017 nikola.tomic@epitech.eu
** Last update Sat May 20 02:04:33 2017 
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

static void	right_arrow(char *file, char mode)
{
  int		fd;

  if (!file)
    return;
  if (mode == 0)
    fd = open(file, (O_WRONLY | O_CREAT | O_TRUNC),
	      (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
  else
    fd = open(file, (O_WRONLY | O_CREAT | O_APPEND),
	      (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
  if (fd == -1)
    return;
  dup2(fd, 1);
  close(fd);
}

static void	left_arrow(char *file, char mode)
{
  int		fd;
  int		pp[2];

  if (mode == 0)
    {
      if (!file || (fd = open(file, O_RDONLY)) == -1)
	return;
    }
  else
    {
      if (pipe(pp) == -1)
	return;
      if (fork() == 0)
	my_heredoc(pp, file);
      wait(NULL);
      fd = pp[0];
    }
  dup2(fd, 0);
  close(fd);
  free(file);
}

char	*redirections(char *cmd)
{
  int	i;

  if (!cmd)
    return (NULL);
  i = my_strlen(cmd) - 1;
  while (i >= 0)
    {
      if (cmd[i] == '>')
	{
	  right_arrow(my_strip(&cmd[i + 1], " \t\n"),
		      (i > 0 && cmd[i - 1] == '>') ? 1 : 0);
	  i = (i > 0 && cmd[i - 1] == '>') ? i - 1 : i;
	  cmd[i] = 0;
	}
      if (cmd[i] == '<')
	{
	      left_arrow(my_strip(&cmd[i + 1], " \t\n"),
			 (i > 0 && cmd[i - 1] == '<') ? 1 : 0);
	      i = (i > 0 && cmd[i - 1] == '<') ? i - 1 : i;
	      cmd[i] = 0;
	}
      i -= 1;
    }
  return (cmd);
}

static int	is_pipable(char *cmd)
{
  epur_str(cmd);
  if (!cmd
      || strncmp(cmd, "cd", 2) == 0
      || strncmp(cmd, "unsetenv", 8) == 0
      || (strncmp(cmd, "setenv", 6) == 0
	  && strcmp(cmd, "setenv") != 0))
    return (0);
  return (1);
}

static void	pipe_loop(t_btree *tmp, int *ret, t_list **dupenvp)
{
  if (tmp->cmd)
    {
      if ((is_pipable(tmp->cmd) || builtins(tmp->cmd, dupenvp, ret) == 0)
	  && fork() == 0)
	{
	  if (dup2(tmp->pp[1], 1) == -1)
	    exit(*ret);
	  close(tmp->pp[0]);
          redirections(tmp->cmd);
	  if (!builtins(tmp->cmd, dupenvp, ret))
	    execution(tmp->cmd, *dupenvp, ret);
	  exit(*ret);
	}
      close(tmp->pp[1]);
    }
  if (tmp && tmp->parent && tmp->parent->right && tmp->parent->right->cmd &&
      (is_pipable(tmp->parent->right->cmd)
       || builtins(tmp->parent->right->cmd, dupenvp, ret) == 0) && fork() == 0)
    {
      if (dup2(tmp->pp[0], 0) == -1)
	exit(*ret);
      close(tmp->pp[1]);
      if (tmp->parent->parent)
	{
	  if (dup2(tmp->parent->right->pp[1], 1) == -1)
	    exit(*ret);
	  close(tmp->parent->right->pp[0]);
	}
      redirections(tmp->parent->right->cmd);
      if (!builtins(tmp->parent->right->cmd, dupenvp, ret))
	execution(tmp->parent->right->cmd, *dupenvp, ret);
      exit(*ret);
    }
  if (tmp && tmp->parent && tmp->parent->right)
    close(tmp->parent->right->pp[1]);
}

int	my_count(char *str, char c)
{
  int	i;
  int	count;

  if (!str)
    return (0);
  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] == c)
	count++;
      i++;
    }
  return (count);
}

int	my_tablen(char **tab)
{
  int	i;

  if (!tab)
    return (0);
  i = 0;
  while (tab[i])
    i++;
  return (i);
}

static int	check_cmds(char **tab, int *ret, char *cmd)
{
  int		i;

  if (!tab || !ret || !cmd)
    return (0);
  if (my_tablen(tab) < my_count(cmd, '|') + 1)
    {
      my_putstr("Invalid null command.\n");
      *ret = 1;
      return (0);
    }
  i = 0;
  while (tab[i])
    {
      epur_str(tab[i]);
      if (!(*tab[i]))
	{
	  my_putstr("Invalid null command.\n");
	  *ret = 1;
	  return (0);
	}
      i++;
    }
  return (1);
}

int		my_pipes(char *cmd, int *ret, t_list **dupenvp)
{
  t_btree	*tree;
  t_btree	*tmp;
  char		**tab;
  int		len;
  int		worst_status;

  if (!cmd || !ret || !(tab = my_str_to_wordtab(cmd, "|"))
      || !check_cmds(tab, ret, cmd) || !(tree = make_tree(tab)))
    return (1);
  tmp = get_outermost(tree, LEFT);
  len = tab_len(tab) + 1;
  while (tmp && tmp->parent)
    {
      pipe_loop(tmp, ret, dupenvp);
      tmp = tmp->parent;
    }
  worst_status = 0;
  while (--len)
    {
      check_status(ret);
      worst_status = (*ret) ? *ret : worst_status;
    }
  free_tree(tree);
  free_tab(tab);
  return ((*ret = worst_status));
}
