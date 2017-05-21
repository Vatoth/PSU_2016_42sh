/*
** exec.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Mon May 15 15:09:15 2017 Léandre Blanchard
** Last update Sun May 21 15:25:00 2017 
*/

#include <string.h>
#include <stdio.h>
#include <wordexp.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "define.h"
#include "my.h"

int             execution(char *cmd, t_env *my_env,
			  int fd)
{
  char          **tabenvp;
  char          **args;
  wordexp_t	p;
  struct stat   buf;

  if (strncmp(cmd, LS, 2) == 0 || strncmp(cmd, GREP, 4) == 0)
    cmd = add_color(cmd);
  if ((recreate_env(&(my_env->env)) == -1) ||
      (wordexp(cmd, &p, 0) != 0) || (args = p.we_wordv) == NULL ||
      !(args[0] = my_strcat(find_path(my_env->env, args[0]), args[0])))
    return (-1);
  tabenvp = list_to_tab(my_env->env);
  stat(args[0], &buf);
  if (access(args[0], F_OK) == -1 || !my_strstr(args[0], "/"))
    my_env->ret = my_error(args[0], CMD_NOT_FOUND, 1, fd);
  else if (access(args[0], X_OK) == -1 || S_ISDIR(buf.st_mode))
    my_env->ret = my_error(args[0], BAD_PERMISSIONS, 1, fd);
  else if (execve(args[0], args, tabenvp) == -1)
    my_env->ret = my_error(args[0], NOT_EXEC, 1, fd);
  else
    my_env->ret = 0;
  free_tab(tabenvp);
  wordfree(&p);
  return (0);
}
