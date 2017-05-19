/*
** parse.c for  in /home/vatoth/Epitech/PSU_2016_42sh
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Mon May 15 14:05:45 2017 
** Last update Sat May 20 00:34:06 2017 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

static int	check_simple_quote(const char *s, int *i)
{
  if (s[*i] == '\'')
    {
      *i = *i + 1;
      while (s[*i] != '\0' && s[*i] != '\'')
	*i = *i + 1;
      if (s[*i] == '\0')
	{
	  puts("Unmatched '''.");
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
          puts("Unmatched '`'.");
          return (1);
        }
    }
  return (0);
}

static int	check_ambigus(const char *s)
{
  int		i;

  i = -1;
  while (s[++i] != '\0')
    {
      if (s[i] == '"')
	{
	  i++;
	  while (s[i] != '\0' && s[i] != '"')
	    i++;
	  if (s[i] == '\0')
	    {
	      puts("Unmatched '\"'.");
	      return (1);
	    }
	}
      if (check_simple_quote(s, &i) == 1)
	return (1);
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

static int                     take_argument(t_info *list, char *s,
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

static int	my_parse_continue(t_info *list, char *s,
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

static int	parse_and(t_info *list, char *s,
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

static int	check_parse(const char *s)
{
  if ((s[0] == '|' && s[1] && s[1] == '|'))
    {
      puts("Invalid null command.");
      return (1);
    }
  if (check_ambigus(s) == 1)
    return (1);
  return (0);
}

int                     my_parse(t_info *list, char *s)
{
  int                   a;
  int                   rest;

  list->i = -1;
  if (check_parse(s) == 1)
    return (1);
  a = 0;
  rest = 0;
  while (s[++(list->i)])
    {
      if (my_parse_continue(list, s, &a, &rest) == -1 ||
	  parse_and(list, s, &a, &rest) == -1)
	return (-1);
      if (!(s[list->i]))
	break;
    }
  if (rest != list->i)
    {
      list->i = strlen(s);
      if (take_argument(list, s, '\0', a) == -1)
        return (-1);
    }
  return (explore(list));
}

int		explore(t_info *list)
{
  t_parse	*parse;

  parse = list->first;
  while (parse)
    {
      if (((parse->token == '&' || parse->token == '|') &&
	   (parse->next == NULL)) ||
	  ((parse->token == '&' || parse->token == '|') &&
	   ((parse->line == NULL) || (parse->line[0] == 0)))
	  || (strcmp(parse->line, "||") == 0))
	{
	  puts("Invalid null command.");
	  clear_list(list);
	  return (1);
	}
      parse = parse->next;
    }
  return (0);
}

void		clear_list(t_info *list)
{
  t_parse       *parse;
  t_parse       *tmp;

  parse = list->first;
  while (parse)
    {
      tmp = parse;
      parse = parse->next;
      if (tmp->line)
	free(tmp->line);
      free(tmp);
    }
  list->first = NULL;
  list->last = NULL;
}
