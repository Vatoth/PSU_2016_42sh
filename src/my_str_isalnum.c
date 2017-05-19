/*
** my_str_isalnum.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Apr 04 19:30:22 2017 nikola.tomic@epitech.eu
** Last update Tue Apr 04 19:37:17 2017 nikola.tomic@epitech.eu
*/

#include "my.h"

int	my_str_isalnum(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i] != 0)
    {
      if (my_isalnum(str[i]) == 0)
	return (0);
      i += 1;
    }
  return (1);
}
