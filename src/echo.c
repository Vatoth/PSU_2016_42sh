/*
** echo.c for echo in /home/homegan/projects/PSU_2016_42sh/src
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Mon May 15 16:15:54 2017 Antoine
** Last update Sat May 20 16:56:52 2017 Antoine
*/

#include <unistd.h>
#include <stdio.h>
#include <wordexp.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "echo.h"

static void	init_tab_fct(t_sp_fcts (fct)[3])
{
  fct[0].name = 'n';
  fct[0].fct = &echo_without_n;
  fct[1].name = 'e';
  fct[1].fct = &with_backslash;
  fct[2].name = 'E';
  fct[2].fct = &without_backslash;
}

static void	echo3(char **tab, t_sp_fcts fct[3],
		      int i, t_sp_flag *var)
{
  (*var).index_flag = 0;
  while ((*var).index_flag < 3)
    {
      if (tab[i][(*var).index_tab] == fct[(*var).index_flag].name)
	{
	  fct[(*var).index_flag].fct(var);
	  break;
	}
      (*var).index_flag++;
    }
  if ((*var).index_flag == 3)
    {
      (*var).args = 0;
      if ((*var).printed == 1)
	my_putchar(' ');
      (*var).printed = 1;
      if ((*var).print_sp != 0)
	my_putstr_without_sp(tab[i]);
      else
	my_putstr(tab[i]);
    }
}

static void	echo2(char **tab, t_sp_fcts fct[3],
		      int i, t_sp_flag *var)
{
  if ((*var).printed == 0 && tab[i][0] == '-')
    {
      (*var).index_tab = 1;
      while (tab[i][(*var).index_tab] != '\0')
	{
	  echo3(tab, fct, i, var);
	  (*var).index_tab++;
	}
    }
  else
    {
      (*var).args = 0;
      if ((*var).printed == 1)
	my_putchar(' ');
      (*var).printed = 1;
      if ((*var).print_sp != 0)
	my_putstr_without_sp(tab[i]);
      else
	my_putstr(tab[i]);
    }
}

int		my_echo(char *str)
{
  char		**tab;
  int		i;
  t_sp_fcts	fct[3];
  t_sp_flag	var;
  wordexp_t	p;

  shift_left(str, 5);
  init_tab_fct(fct);
  var.print_sp = 0;
  var.args = 1;
  var.without_return = 0;
  var.printed = 0;
  if (wordexp(str, &p, 0) != 0)
    return (1);
  tab = p.we_wordv;
  if (tab == NULL)
    return (putchar('\n'));
  i = -1;
  while (tab[++i] != NULL)
    echo2(tab, fct, i, &var);
  if (var.without_return == 0)
    my_putstr("\n");
  wordfree(&p);
  return (0);
}
