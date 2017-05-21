/*
** init_execution.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 21 14:52:56 2017 Léandre Blanchard
** Last update Sun May 21 17:17:40 2017 Léandre Blanchard
*/

#include <unistd.h>
#include <stdlib.h>
#include "define.h"
#include "my.h"

int			recreate_path(t_list **dupenvp, char *s)
{
  size_t        n;
  char          *prev;

  if (check_env(*dupenvp, VAR_PATH) == 1)
    {
      n = confstr(_CS_PATH, NULL, (size_t)0);
      if ((s = malloc(n)) == NULL)
	return (1);
      confstr(_CS_PATH, s, n);
      setenv(VAR_PATH, s, 1);
      prev = s;
      if ((s = my_catalloc("PATH=", prev, NULL)) == NULL)
	return (1);
      put_in_list(dupenvp, s);
      free(s);
      free(prev);
    }
  return (0);
}

int			parse_loop(t_info *list, t_parse *shell,
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

char			*source_cmd(char **cmds)
{
  static int    a = -1;
  char		*retur;

  if (a == -1)
    via_pipe(&a);
  disp_prompt();
  if (a != 0)
    {
      retur = get_next_line(0);
      epur_str(retur);
      return (retur);
    }
  retur = get_cmd(cmds);
  epur_str(retur);
  return (retur);
}

int			check_env(t_list *dupenvp, char *var)
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

int			preparation(char *cmd, t_env *my_env,
			    t_list_al *alias)
{
  if (my_str_isascii(cmd) == 1)
    {
      write(2, BAD_CHAR, my_strlen(BAD_CHAR));
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
	  execution(cmd, my_env, 1);
	  exit(my_env->ret);
	}
      check_status(&(my_env->ret));
    }
  return (0);
}
