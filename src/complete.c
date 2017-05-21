/*
** complete.c for  in /home/vatoth/Epitech/PSU_2016_42sh
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat May 20 18:09:11 2017 
** Last update Sun May 21 16:50:33 2017 Léandre Blanchard
*/

#include "completion.h"

char		**glob_tab(const char *s)
{
  glob_t	p;

  p.gl_pathc = 0;
  p.gl_pathv = NULL;
  p.gl_offs = 0;
  if (glob(s, GLOB_MARK | GLOB_TILDE, NULL, &p) != 0)
    return (NULL);
  if (my_tablen(p.gl_pathv) > 1)
    {
      my_printf("\n");
      my_put_tabw("", p.gl_pathv, "\t");
      my_printf("\n");
    }
  return (p.gl_pathv);
}

char		*get_new(char *s, int cur)
{
  char          *first;
  int           i;

  i = cur - 1;
  while (i >= 0 && s[i] != ' ')
    i--;
  if ((first = my_calloc(i + my_strlen(s) + 10)) == NULL)
    return (NULL);
  if (cur - i > 0)
    my_strncpy(first, s + i, cur - i);
  else
    my_strcpy(first, s + i);
  epur_str(first);
  return (first);
}

char		*get_end(char *s, int cur)
{
  char          *end;

  if ((end = my_calloc(my_strlen(s) + 10)) == NULL)
    return (NULL);
  my_strcpy(end, s + cur);
  return (end);
}

char		*get_start(char *s, int cur, int size)
{
  char          *start;
  int           len;

  len = cur - size;
  if ((start = my_calloc(len + 10)) == NULL)
    return (NULL);
  my_strncpy(start, s, len);
  return (start);
}
