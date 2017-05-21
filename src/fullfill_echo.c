/*
** fullfill_echo.c for fullfill_echo in /home/homegan/projects/PSU_2016_42sh
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Sat May 20 16:55:24 2017 Antoine
** Last update Sat May 20 16:56:50 2017 Antoine
*/

#include <unistd.h>
#include <stdio.h>
#include <wordexp.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "echo.h"

void	fullfill_sp_tab(t_sp_car sp_tab[10])
{
  sp_tab[0].name = 'n';
  sp_tab[0].corresp = '\n';
  sp_tab[1].name = '\\';
  sp_tab[1].corresp = '\\';
  sp_tab[2].name = 'a';
  sp_tab[2].corresp = '\a';
  sp_tab[3].name = 'b';
  sp_tab[3].corresp = '\b';
  sp_tab[4].name = 'c';
  sp_tab[4].corresp = '\0';
  sp_tab[5].name = 'e';
  sp_tab[5].corresp = '\e';
  sp_tab[6].name = 'f';
  sp_tab[6].corresp = '\f';
  sp_tab[7].name = 'r';
  sp_tab[7].corresp = '\r';
  sp_tab[8].name = 't';
  sp_tab[8].corresp = '\t';
  sp_tab[9].name = 'v';
  sp_tab[9].corresp = '\v';
}

int		my_putstr_without_sp(char *c)
{
  int		i;
  t_sp_car	sp_tab[10];
  int		index_sptab;

  fullfill_sp_tab(sp_tab);
  i = 0;
  while (c[i] != '\0')
    {
      index_sptab = 0;
      while (index_sptab < 10)
	{
	  if (c[i] == '\\' && sp_tab[index_sptab].name == c[i + 1])
	    {
	      my_putchar(sp_tab[index_sptab].corresp);
	      index_sptab = 0;
	      i++;
	      break;
	    }
	  index_sptab++;
	}
      if (index_sptab == 10)
	my_putchar(c[i]);
      i++;
    }
  return (0);
}

int	echo_without_n(t_sp_flag *var)
{
  var->without_return = 1;
  return (0);
}

int	with_backslash(t_sp_flag *var)
{
  var->print_sp = 2;
  return (0);
}

int	without_backslash(t_sp_flag *var)
{
  if (var->print_sp != 2)
    var->print_sp = 0;
  return (0);
}
