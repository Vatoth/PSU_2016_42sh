/*
** my_get_var.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Mon Apr 03 16:28:24 2017 nikola.tomic@epitech.eu
** Last update Sun May 21 14:50:49 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char		*my_get_var(t_list *list, char *var)
{
  t_list	*tmp;
  char		*varcpy;
  char		*ret;
  char		*equals;

  if (!var || !(varcpy = (var[my_strlen(var) - 1] != '=') ?
		my_strcat(var, "=") : my_strdup(var)))
    return (NULL);
  tmp = list;
  while (tmp && my_strncmp(tmp->var, varcpy, my_strlen(varcpy)) != 0)
    tmp = tmp->next;
  if (!tmp || !(equals = my_strstr(tmp->var, "=")) ||
      !(ret = my_strdup(equals + 1)))
    return (NULL);
  if (varcpy)
    free(varcpy);
  return (ret);
}

int	my_error(char *cmd, char *msg, int ret, int fd)
{
  char	*disp;

  if (!(disp = my_catalloc(cmd, msg, NULL)))
    return (0);
  if (disp)
    {
      write(fd, disp, my_strlen(disp));
      free(disp);
    }
  return (ret);
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb *= -1;
      my_putnbr('-');
    }
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}

int	cnt(char *str, char c)
{
  int	i;
  int	count;

  if (!str)
    return (0);
  i = 0;
  count = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	count += 1;
      i += 1;
    }
  return (count);
}

char	*my_strip(char *str, char *to_strip)
{
  char	*ret;
  int	i;
  int	y;

  if (!str || !to_strip || !(ret = (char *) malloc(my_strlen(str) + 1)))
    return (str);
  i = 0;
  y = 0;
  while (str[y] != 0)
    {
      if (cnt(to_strip, str[y]) == 0)
	{
	  ret[i] = str[y];
	  i += 1;
	}
      y += 1;
    }
  ret[i] = 0;
  return (ret);
}
