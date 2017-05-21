/*
** parse2.c for parse2 in /home/homegan/projects/tmp/PSU_2016_42sh
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Sun May 21 17:39:47 2017 Antoine
** Last update Sun May 21 17:42:34 2017 Antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

int	check_simple_quote(const char *s, int *i)
{
  if (s[*i] == '\'')
    {
      *i = *i + 1;
      while (s[*i] != '\0' && s[*i] != '\'')
	*i = *i + 1;
      if (s[*i] == '\0')
	{
	  write(2, "Unmatched '''.\n", 15);
	  return (1);
	}
    }
  if (s[*i] == '`')
    {
      *i = *i + 1;
      while (s[*i] != '\0' && s[*i] != '`')
        *i = *i + 1;
      if (s[*i] == '\0')
        {
          write(2, "Unmatched '`'.\n", 15);
          return (1);
        }
    }
  return (0);
}

static void			make_link(t_parse *new_element,
					  t_info *list, const char token,
					  const int j)
{
  memset(new_element->line, 0, j + 1);
  new_element->token = token;
  new_element->prev = list->last;
  new_element->next = NULL;
  if (list->last)
    list->last->next = new_element;
  else
    list->first = new_element;
  list->last = new_element;
}

int                     take_argument(t_info *list, char *s,
				      const char token,
				      const int a)
{
  int				j;
  int				i;
  t_parse			*new_element;

  i = a - 1;
  j = 0;
  while (s[++i] && (i <= (list->i - 1)))
    j++;
  if (j == 0)
    return (0);
  if (!(new_element = malloc(sizeof(t_parse)))
      || !(new_element->line = malloc(sizeof(char) * (j + 1))))
    return (-1);
  make_link(new_element, list, token, j);
  i = a;
  j = 0;
  while (s[i] && (i <= (list->i - 1)))
    {
      new_element->line[j] = s[i];
      j++;
      i++;
    }
  epur_str(new_element->line);
  return (0);
}

int	my_parse_continue(t_info *list, char *s,
				  int *a, int *rest)
{
  if (s[list->i] == '"')
    {
      list->i++;
      while (s[list->i] != '\0' && s[list->i] != '"')
	list->i++;
    }
  if (s[list->i] == '\'')
    {
      list->i++;
      while (s[list->i] != '\0' && s[list->i] != '\'')
	list->i++;
    }
  if (s[list->i] == '|' && s[list->i + 1] != '\0' && s[list->i + 1] == '|')
    {
      if (take_argument(list, s, '|', *a) == -1)
	return (-1);
      list->i = list->i + 2;
      *a = list->i;
      *rest = list->i;
    }
  return (0);
}

int	parse_and(t_info *list, char *s,
			  int *a, int *rest)
{
  if (s[list->i] == ';')
    {
      if (take_argument(list, s, ';', *a) == -1)
	return (-1);
      list->i++;
      *a = list->i;
      *rest = list->i;
    }
  if (s[list->i] && s[list->i] == '&' && s[list->i + 1]
      && s[list->i + 1] == '&')
    {
      if (take_argument(list, s, '&', *a) == -1)
	return (-1);
      list->i = list->i + 2;
      *a = list->i;
      *rest = list->i;
    }
  return (0);
}
