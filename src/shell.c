/*
** shell.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh/src
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sun May 14 23:44:43 2017 Léandre Blanchard
** Last update Sun May 21 15:52:39 2017 
*/

#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "my.h"

int		recreate_env(t_list **dupenvp)
{
  char          *s;

  if (check_env(*dupenvp, VAR_USER) == 1)
    {
      if ((s = my_catalloc("USER=",
			   getpwuid(getuid())->pw_name, NULL)) == NULL)
        return (1);
      setenv(VAR_USER, getpwuid(getuid())->pw_name, 1);
      put_in_list(dupenvp, s);
      free(s);
    }
  if (recreate_path(dupenvp, s) == 1)
    return (1);
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
