/*
** echo.c for echo in /home/homegan/projects/PSU_2016_42sh/src
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Mon May 15 16:15:54 2017 Antoine
** Last update Sat May 20 00:43:01 2017 
*/

#include <unistd.h>
#include <stdio.h>
#include <wordexp.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

typedef struct	s_sp_car
{
  char		name;
  char		corresp;
}		t_sp_car;

typedef struct	s_echo_flag
{
  int		without_return;
  int		args;
  int		print_sp;
  int		printed;
}		t_sp_flag;

typedef struct	s_sp_fcts
{
  char		name;
  int		(*fct)(t_sp_flag *);
}		t_sp_fcts;

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

static void	init_tab_fct(t_sp_fcts (fct)[3])
{
  fct[0].name = 'n';
  fct[0].fct = &echo_without_n;
  fct[1].name = 'e';
  fct[1].fct = &with_backslash;
  fct[2].name = 'E';
  fct[2].fct = &without_backslash;
}

static void	echo2(char **tab, t_sp_fcts fct[3],
		      int i, t_sp_flag *var)
{
  int  	index_flag;
  int	index_tab;

  if ((*var).printed == 0 && tab[i][0] == '-')
    {
      index_tab = 1;
      while (tab[i][index_tab] != '\0')
	{
	  index_flag = 0;
	  while (index_flag < 3)
	    {
	      if (tab[i][index_tab] == fct[index_flag].name)
		{
		  fct[index_flag].fct(var);
		  break;
		}
	      index_flag++;
	    }
	  if (index_flag == 3)
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
	  index_tab++;
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
