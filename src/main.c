/*
** main.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Mon Apr 03 13:49:13 2017 nikola.tomic@epitech.eu
** Last update Sat May 20 11:59:02 2017 
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "my.h"

extern char	**environ;

void			check_status(int *ret)
{
  int			status;
  int			sig;

  status = 0;
  wait(&status);
  if (WIFEXITED(status))
    *ret = WEXITSTATUS(status);
  else if (WIFSIGNALED(status))
    {
      sig = WTERMSIG(status);
      if (sig == SIGABRT)
	my_putstr("Aborted");
      else if (sig == SIGFPE)
	my_putstr("Floating exception");
      else if (sig == SIGSEGV)
	my_putstr("Segmentation fault");
      else
	my_putstr("Signal received");
      if (WCOREDUMP(status))
	my_putstr(" (core dumped)");
      my_putchar('\n');
      *ret = sig + 128;
    }
}

int			main(void)
{
  t_list		*dupenvp;
  struct termios	old;
  int			ret;

  signal(SIGINT, sigint_handler);
  ioctl(0, TCGETS, &old);
  ret = 0;
  dupenvp = tab_to_list(environ);
  if (via_pipe(NULL) == 0)
    routine_ioctl();
  mainloop(dupenvp, &ret);
  free_list(dupenvp);
  if (!via_pipe(NULL))
    my_putchar('\n');
  ioctl(0, TCSETS, &old);
  return (ret);
}
