/*
** shell.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh/src
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sun May 14 23:44:43 2017 Léandre Blanchard
** Last update Sun May 21 10:12:30 2017 
*/

#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "my.h"

static int	preparation(char *cmd, t_env *my_env,
			    t_list_al *alias)
{
  if (my_str_isascii(cmd) == 1)
    {
      my_printf("Error: unhandled characters in input\n");
      return (-1);
    }
  if (my_strstr(cmd, "|"))
    my_pipes(cmd, my_env, alias);
  else if (builtins(cmd, my_env, alias) == 0)
    {
      if (fork() == 0)
	{
	  if (!(cmd = redirections(cmd)))
	    exit(my_env->ret);
	  execution(cmd, my_env, 1, alias);
	  exit(my_env->ret);
	}
      check_status(&(my_env->ret));
    }
  return (0);
}

static int	parse_loop(t_info *list, t_parse *shell,
			   t_env *my_env, t_list_al *alias)
{
  shell = list->first;
  while (shell != NULL)
    {
      preparation(shell->line, my_env, alias);
      if ((shell->token == '&' && my_env->ret != 0) ||
	  (shell->token == '|' && my_env->ret == 0))
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

void		protect_alias(char *s)
{
  int		i;

  i = 0;
  while (s != NULL && s[i] != '\0')
    {
      if (s[i] == '"')
	{
	  i++;
	  while (s[i] != '\0' && s[i] != '"')
	    {
	      if (s[i] == ' ')
		s[i] = -1;
	      i++;
	    }
	}
      i++;
    }
}

int		count_quote(const char *s)
{
  int		i;
  int		quote;

  i = 0;
  quote = 0;
  while (s[i] != '\0')
    {
      if (s[i] == '"')
	quote++;
      i++;
    }
  return (quote);
}

int		init_alias(t_list_al *alias)
{
  char		**tab;
  char		*s;
  int		i;

  if ((alias->file = update_from_file("/.42shrc")) == NULL)
    return (1);
  alias->first = NULL;
  alias->last = NULL;
  i = -1;
  while (alias->file[++i] != NULL)
    {
      if (strncmp(alias->file[i], "alias", 5) == 0 &&
	  (count_quote(alias->file[i]) == 2 ||
	   count_quote(alias->file[i]) == 0))
	{
	  if ((s = strdup(alias->file[i])) == NULL)
	    return (1);
	  protect_alias(s);
	  if ((tab = my_str_to_wordtab(s, " ")) == NULL)
	    return (1);
	  if (my_tablen(tab) == 3 && count_quote(tab[1]) == 0)
	    if (add_alias(alias, tab[1], tab[2]) == -1)
	      return (1);
	  free(s);
	  free_tab(tab);
	}
    }
  return (0);
}

static int	loop(t_env *my_env, t_info *list)
{
  char		*ln;
  char		**cmds;
  t_list_al	alias;	

  ln = NULL + 1;
  if (recreate_env(&(my_env->env)) == 1 ||
      (cmds = update_from_file("/.42sh_history")) == NULL
      || (init_alias(&alias)) == 1)
    return (84);
  while (ln != NULL)
    {
      if ((ln = source_cmd(cmds)) == NULL)
	break;
      epur_str(ln);
      if (ln != NULL && ln[0] != 0)
	{
	  if ((my_env->ret = (my_parse(list, ln))) == -1)
	    return (84);
	  parse_loop(list, list->first, my_env, &alias);
	}
      save_cmd(ln);
      cmds = tab_append(cmds, ln);
    }
  free_alias(&alias);
  free_tab(cmds);
  return (0);
}

int		mainloop(t_env *my_env)
{
  t_info	*list;

  if ((list = malloc(sizeof(t_info))) == NULL)
    return (84);
  list->first = NULL;
  list->last = NULL;
  if (loop(my_env, list) == 84)
    return (84);
  clear_list(list);
  if (list)
    free(list);
  return (my_env->ret);
}
