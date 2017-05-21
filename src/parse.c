/*
** parse.c for  in /home/vatoth/Epitech/PSU_2016_42sh
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Mon May 15 14:05:45 2017 
** Last update Sun May 21 17:52:04 2017 Antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

static int	check_parse(const char *s)
{
  if ((s[0] == '|' && s[1] && s[1] == '|'))
    {
      write(2, "Invalid null command.\n", 23);
      return (1);
    }
  if (check_ambigus(s) == 1)
    return (1);
  return (0);
}

int		check_ambigus(const char *s)
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
	      write(2, "Unmatched '\"'.\n", 15);
	      return (1);
	    }
	}
      if (check_simple_quote(s, &i) == 1)
	return (1);
    }
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
	  write(2, "Invalid null command.\n", 23);
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
