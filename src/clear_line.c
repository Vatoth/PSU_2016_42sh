/*
** epur_str.c for epur_str in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Mar 13 14:38:15 2017 Léandre Blanchard
** Last update Tue May 16 17:38:45 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include "my.h"

void		zeros(char *s, int size)
{
  int		i;

  i = 0;
  while (i != size)
    s[i++] = 0;
}

static int	finish_whole(char *s, char *str)
{
  if (s[my_strlen(s) - 1] == ' ')
    s[my_strlen(s) - 1] = 0;
  zeros(str, my_strlen(str) + 1);
  my_strcpy(str, s);
  return (0);
}

int		epur_str(char *str)
{
  char	s[my_strlen(str) + 1];
  int	i;
  int	j;

  if (str == NULL)
    return (-1);
  zeros(s, my_strlen(str) + 1);
  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  if (j != 0)
	    s[j++] = ' ';
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
      if (str[i] != 0)
	s[j++] = str[i++];
    }
  finish_whole(s, str);
  return (0);
}
