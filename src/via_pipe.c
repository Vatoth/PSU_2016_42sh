/*
** via_pipe.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May 16 18:07:35 2017 Léandre Blanchard
** Last update Tue May 16 18:09:32 2017 Léandre Blanchard
*/

#include <termios.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int			via_pipe(int *ret)
{
  int			i;
  struct termios	test;

  i = ioctl(0, TCGETS, &test);
  if (ret != NULL)
    *ret = i;
  return (i);
}
