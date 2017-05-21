/*
** 42sh_history.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 17 18:08:29 2017 Léandre Blanchard
** Last update Sun May 21 15:29:55 2017 
*/

#include "42sh_history.h"
#include "colors.h"

static int	write_cmd(const char *cmd)
{
  int		fd;
  char		*filename;

  if ((filename = get_path(PATH_HISTORY)) == NULL)
    return (-1);
  if ((fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666)) < 0)
    return (-1);
  if (write(fd, cmd, my_strlen(cmd)) < 0)
    return (-1);
  if (write(fd, "\n", 1) < 0)
    return (-1);
  free(filename);
  close(fd);
  return (0);
}

static int	get_size(int fd)
{
  int		size;

  size = 0;
  if ((size = lseek(fd, 0, SEEK_END)) > MASSIVE)
    {
      if (isatty(1))
	my_printf(BOLDRED);
      my_printf(WARNING_MASSIVE);
      if (isatty(1))
	my_printf(RESET);
      my_printf("%d MB\n", size / 1000);
      my_printf(ONLY_LASTS);
      size = 1000;
      lseek(fd, -1000, SEEK_END);
    }
  else
    lseek(fd, 0, 0);
  return (size);
}

static char	**create_history(const char *file)
{
  char		*filename;
  char		**cmds;
  char		*s;
  int		fd;
  int		size;

  if ((filename = get_path(file)) == NULL)
    return (NULL);
  if ((fd = open(filename, O_RDONLY | O_CREAT, 0666)) < 0)
    return (NULL);
  free(filename);
  size = get_size(fd);
  if ((s = my_calloc(size + 1)) == NULL)
    return (NULL);
  if (read(fd, s, size) < 0)
    return (NULL);
  if ((cmds = basic_wordtab(s, '\n')) == NULL)
    return (NULL);
  free(s);
  return (cmds);
}

char		**update_from_file(const char *filename)
{
  char		**tab;

  if ((tab = create_history(filename)) == NULL)
    {
      if ((tab = malloc(sizeof(char *) * 2)) == NULL)
	return (NULL);
      tab[0] = NULL;
      tab[1] = NULL;
    }
  return (tab);
}

int		save_cmd(const char *cmd)
{
  if (cmd[0] == 10 || cmd[0] == 0)
    return (0);
  if ((write_cmd(cmd)) == -1)
    {
      my_printf(ISSUE_SAVE);
      return (-1);
    }
  return (0);
}
