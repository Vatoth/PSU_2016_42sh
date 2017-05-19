/*
** prompt.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 14 21:32:10 2017 Léandre Blanchard
** Last update Fri May 19 09:59:24 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "colors.h"
#include "my.h"

static void	rm_slashs(char *pwd)
{
  while (nb_of(pwd, '/') >= 1)
    shift_left(pwd, 1);
}

static void	color(char *pwd)
{
  int		with;

  with = 0;
  if (pwd != NULL)
    {
      if (nb_of(pwd, '/') == 2)
	with = 1;
      if (strcmp(pwd, "/") != 0)
	rm_slashs(pwd);
      if (with == 0)
	my_printf("%s➜  %s%s%s > %s",
		  BOLDGREEN, BOLDCYAN, pwd, BOLDYELLOW, RESET);
      if (with == 1)
	my_printf("%s➜  %s~%s > %s",
		  BOLDGREEN, BOLDCYAN, BOLDYELLOW, RESET);
    }
}

void		disp_prompt(void)
{
  char		*pwd;

  if (isatty(0))
    {
      if ((pwd = getcwd(NULL, 0)) == NULL)
	printf("$> ");
      color(pwd);
      if (pwd)
	free(pwd);
    }
}
