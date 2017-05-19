/*
** shell.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh/src
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sun May 14 23:44:43 2017 Léandre Blanchard
** Last update Sat May 20 00:39:47 2017 
*/

#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "my.h"

static int	preparation(char *cmd, int *ret, t_list **dupenvp)
{
  if (my_str_isascii(cmd) == 1)
    {
      my_printf("Error: unhandled characters in input\n");
      return (-1);
    }
  if (my_strstr(cmd, "|"))
    my_pipes(cmd, ret, dupenvp);
  else if (builtins(cmd, dupenvp, ret) == 0)
    {
      if (fork() == 0)
	{
	  if (!(cmd = redirections(cmd)))
	    exit(*ret);
	  execution(cmd, *dupenvp, ret);
	  exit(*ret);
	}
      check_status(ret);
    }
  return (0);
}

static int	parse_loop(t_info *list, t_parse *shell,
			   int *ret, t_list *dupenvp)
{
  shell = list->first;
  while (shell != NULL)
    {
      preparation(shell->line, ret, &dupenvp);
      if ((shell->token == '&' && *ret != 0) ||
	  (shell->token == '|' && *ret == 0))
	break;
      shell = shell->next;
    }
  clear_list(list);
  return (0);
}

static char    	*source_cmd(char **cmds)
{
  static int	a = -1;

  if (a == -1)
    via_pipe(&a);
  disp_prompt();
  if (a != 0)
    return (get_next_line(0));
  return (get_cmd(cmds));
}

static int             check_env(t_list *dupenvp, char *var)
{
  if (dupenvp == NULL)
    return (1);
  while (dupenvp->next)
    {
      if (my_strncmp(var, dupenvp->var, 4) == 0)
        return (0);
      dupenvp = dupenvp->next;
    }
  return (1);
}

int		recreate_path(t_list **dupenvp, char *s)
{
  size_t	n;
  char		*prev;
  
  if (check_env(*dupenvp, "PATH") == 1)
    {
      n = confstr(_CS_PATH, NULL, (size_t)0);
      if ((s = malloc(n)) == NULL)
        return (1);
      confstr(_CS_PATH, s, n);
      setenv("PATH=", s, 1);
      prev = s;
      if ((s = my_catalloc("PATH=", prev, NULL)) == NULL)
        return (1);
      put_in_list(dupenvp, s);
      free(s);
      free(prev);
    }
  return (0);
}

int             recreate_env(t_list **dupenvp)
{
  char          *s;

  if (check_env(*dupenvp, "USER") == 1)
    {
      if ((s = my_catalloc("USER=",
			   getpwuid(getuid())->pw_name, NULL)) == NULL)
        return (1);
      setenv("USER", getpwuid(getuid())->pw_name, 1);
      put_in_list(dupenvp, s);
      free(s);
    }
  if (recreate_path(dupenvp, s) == 1)
    return (1);
  return (0);
}

static int	loop(t_list *dupenvp, int *ret, t_info *list)
{
  char		*ln;
  char		**cmds;

  ln = NULL + 1;
  if (recreate_env(&dupenvp) == 1 ||
      (cmds = update_from_file("/.42sh_history")) == NULL)
    return (84);
  while (ln != NULL)
    {
      if ((ln = source_cmd(cmds)) == NULL)
	break;
      epur_str(ln);
      if (ln != NULL && ln[0] != 0)
	{
	  if ((*ret = (my_parse(list, ln))) == -1)
	    return (84);
	  parse_loop(list, list->first, ret, dupenvp);
	}
      save_cmd(ln);
      cmds = tab_append(cmds, ln);
    }
  free_tab(cmds);
  return (0);
}

int		mainloop(t_list *dupenvp, int *ret)
{
  t_info	*list;

  if ((list = malloc(sizeof(t_info))) == NULL)
    return (84);
  list->first = NULL;
  list->last = NULL;
  if (loop(dupenvp, ret, list) == 84)
    return (84);
  clear_list(list);
  if (list)
    free(list);
  return (*ret);
}
