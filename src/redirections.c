/*
** redirections.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Sat Apr 08 13:26:38 2017 nikola.tomic@epitech.eu
** Last update Sat May 20 23:30:04 2017 
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

static void	my_heredoc(int pp[2], char *file)
{
  char		*line;

  while ((line = get_next_line(0)))
    {
      if (my_strcmp(file, line) == 0)
        break;
      write(pp[1], line, my_strlen(line));
      write(pp[1], "\n", 1);
      free(line);
    }
  close(pp[0]);
  close(pp[1]);
  exit(0);
}

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
