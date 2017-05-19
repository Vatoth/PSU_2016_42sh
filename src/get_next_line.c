/*
** get_next_line.c for get_next_line in /home/nikola/new get_next_line
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Sat Mar 18 19:30:16 2017 nikola.tomic@epitech.eu
** Last update Mon May 15 21:14:02 2017 
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int	my_strlen(char *str)
{
  int		i;

  if (!str)
    return (0);
  i = 0;
  while (str[i] != 0)
    i += 1;
  return (i);
}

static char    *my_strncat(char *dest, char *src, int nb, char mode)
{
  char		*ret;
  int		i;
  int		y;

  if (!(ret = (char *)malloc(my_strlen(dest) + nb + 1)))
    return (NULL);
  i = 0;
  if (mode == 'c' && dest)
    {
      while (dest[i] != 0)
	{
	  ret[i] = dest[i];
	  i += 1;
	}
    }
  y = 0;
  while (src && y < nb && src[y] != 0)
    ret[i++] = src[y++];
  ret[i] = 0;
  return (ret);
}

static int	find_new_line(char *line)
{
  int		i;

  if (!line)
    return (-1);
  i = 0;
  while (line[i])
    {
      if (line[i] == '\n')
	return (i);
      i += 1;
    }
  return (-1);
}

static char	*return_line(char *line, char **storage, int new_line)
{
  char		*to_free;

  if (!line || !storage)
    return (NULL);
  to_free = *storage;
  if (!(*storage = my_strncat(*storage, &line[new_line + 1],
			      my_strlen(&line[new_line + 1]), 'd')))
    return (NULL);
  if (to_free && to_free != line)
    free(to_free);
  if (*storage && *storage[0] == 0)
    {
      free(*storage);
      *storage = NULL;
    }
  line[new_line] = 0;
  return (line);
}

char		*get_next_line(int fd)
{
  static char	*storage;
  char		*line;
  char		buff[READ_SIZE];
  int		er;
  int		new_line;
  char		*to_free;

  line = NULL;
  if (storage)
    {
      if ((new_line = find_new_line((line = storage))) >= 0)
	return (return_line(line, &storage, new_line));
      storage = NULL;
    }
  while ((er = read(fd, buff, READ_SIZE)) > 0)
    {
      to_free = line;
      if (!(line = my_strncat(line, (char *)buff, er, 'c')))
	return (NULL);
      if (to_free)
	free(to_free);
      if ((new_line = find_new_line(line)) >= 0)
	return (return_line(line, &storage, new_line));
    }
  return ((er <= 0 && !line) ? NULL : line);
}
