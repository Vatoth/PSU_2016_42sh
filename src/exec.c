/*
** exec.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Mon May 15 15:09:15 2017 Léandre Blanchard
** Last update Sun May 21 10:23:30 2017 
*/

#include <string.h>
#include <stdio.h>
#include <wordexp.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int             execution(char *cmd, t_env *my_env,
			  int fd, t_list_al *alias)
{
  char          **tabenvp;
  char          **args;
  wordexp_t	p;
  struct stat   buf;

  if ((cmd  = replace_alias(cmd, alias)) == NULL)
    return (-1);
  if (strncmp(cmd, "ls", 2) == 0 || strncmp(cmd, "grep", 4) == 0)
    cmd = add_color(cmd);
  if ((recreate_env(&(my_env->env)) == -1) ||
      (wordexp(cmd, &p, 0) != 0) || (args = p.we_wordv) == NULL ||
      !(args[0] = my_strcat(find_path(my_env->env, args[0]), args[0])))
    return (-1);
  tabenvp = list_to_tab(my_env->env);
  stat(args[0], &buf);
  if (access(args[0], F_OK) == -1 || !my_strstr(args[0], "/"))
    my_env->ret = my_error(args[0], ": Command not found.\n", 1, fd);
  else if (access(args[0], X_OK) == -1 || S_ISDIR(buf.st_mode))
    my_env->ret = my_error(args[0], ": Permission denied.\n", 1, fd);
  else if (execve(args[0], args, tabenvp) == -1)
    my_env->ret = my_error(args[0], ": Exec format error. "
		    "Binary file not executable.\n", 1, fd);
  else
    my_env->ret = 0;
  free_tab(tabenvp);
  wordfree(&p);
  return (0);
}
