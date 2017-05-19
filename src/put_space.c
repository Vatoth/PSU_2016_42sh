/*
** put_space.c for put_space.c in /home/homegan/projects/PSU_2016_42sh
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Sun May 14 16:20:16 2017 Antoine
** Last update Mon May 15 23:44:20 2017 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char	*put_space(char *str, int here)
{
  char	*newstr;
  int	i;

  if (!(newstr = malloc(strlen(str) + 2)))
    return (NULL);
  i = -1;
  while (str[++i] != '\0')
    {
      if (i < here)
	newstr[i] = str[i];
      else if (i == here)
	{
	  newstr[i] = ' ';
	  newstr[i + 1] = str[i];
	}
      else if (i > here)
	newstr[i + 1] = str[i];
    }
  if (str)
    free(str);
  newstr[i + 1] = '\0';
  return (newstr);
}

static char	*add_spaces2(char *str, char nb[3], int i)
{
  if (str[i] == '|')
    {
      nb[2]++;
      if (nb[2] == 3)
	{
	  if (!(str = put_space(str, i)))
	    return (NULL);
	  nb[2] = 0;
	}
    }
  else
    nb[2] = 0;
  if (str[i] == ';')
    {
      nb[0]++;
      if (nb[0] == 2)
	{
	  if (!(str = put_space(str, i)))
	    return (NULL);
	  nb[0] = 0;
	}
    }
  else
    nb[0] = 0;
  return (str);
}

char	*add_spaces(char *str)
{
  char	nb[3];
  int	i;

  i = -1;
  nb[0] = 0;
  nb[1] = 0;
  nb[2] = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == '&')
	{
	  nb[1]++;
	  if (nb[1] == 3)
	    {
	      if (!(str = put_space(str, i)))
		return (NULL);
	      nb[1] = 0;
	    }
	}
      else
	nb[1] = 0;
      if (!(str = add_spaces2(str, nb, i)))
	return (NULL);
    }
  return (str);
}
