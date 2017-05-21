/*
** more_tools.c for PSU_2016_42sh in /home/nikola/delivery/PSU_2016_42sh/src
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Sat May 20 17:51:28 2017 nikola.tomic@epitech.eu
** Last update Sun May 21 00:03:38 2017 
*/

#include <string.h>
#include "my.h"

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
  while (tab[i] != NULL)
    i++;
  return (i);
}

int	is_pipable(char *cmd)
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

int	check_cmds(char **tab, int *ret, char *cmd)
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
