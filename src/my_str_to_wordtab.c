/*
** args.c for PSU_2016_minishell1 in /home/nikola/PSU_2016_minishell1
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Jan 17 15:19:39 2017 nikola.tomic@epitech.eu
** Last update Sat May 20 19:44:15 2017 
*/

#include <stdlib.h>
#include "my.h"

static int	my_issep(char c, char *seps)
{
  int		i;

  if (!seps)
    return (1);
  i = 0;
  while (seps[i] != '\0')
    {
      if (c == seps[i])
	return (0);
      i += 1;
    }
  return (1);
}

static char	*get_arg(char *str, int *j, char *seps)
{
  int		i;
  char		*ret;

  i = 0;
  while (my_issep(str[*j], seps) == 0)
    *j += 1;
  while (my_issep(str[*j + i], seps) == 1 && str[*j + i] != '\0')
    i += 1;
  if ((ret = malloc(i + 1)) == NULL)
    return (NULL);
  ret[i] = '\0';
  i = 0;
  while (my_issep(str[*j], seps) == 1 && str[*j] != '\0')
    {
      ret[i] = str[*j];
      i += 1;
      *j += 1;
    }
  return (ret);
}

static int	get_nb_args(char *str, char *seps)
{
  int		i;
  int		y;

  i = 0;
  y = 0;
  while (my_issep(str[y], seps) == 0 && str[y] != '\0')
    y += 1;
  while (str[y] != '\0')
    {
      if (my_issep(str[y], seps) == 1 && str[y] != '\0' &&
	  (my_issep(str[y + 1], seps) == 0 || str[y + 1] == '\0'))
	i += 1;
      y += 1;
    }
  return (i);
}

char	**my_str_to_wordtab(char *str, char *seps)
{
  int	i;
  int	y;
  int	j;
  char	**args;

  if (!str)
    return (NULL);
  if (!seps)
    {
      args = &str;
      return (args);
    }
  y = 0;
  j = 0;
  i = get_nb_args(str, seps);
  if ((args = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  while (y < i)
    {
      args[y] = get_arg(str, &j, seps);
      y += 1;
    }
  args[y] = NULL;
  return (args);
}
