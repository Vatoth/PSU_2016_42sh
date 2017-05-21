/*
** call_completion.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 20 18:27:40 2017 Léandre Blanchard
** Last update Sun May 21 17:14:04 2017 Léandre Blanchard
*/

#include "completion.h"

static char    	**load_or_return(char *new, t_curset *curset)
{
  char		**tab;

  move_and_add(new, my_strlen(new), '*');
  if ((tab = glob_tab(new)) == NULL)
    {
      move_and_ret(curset->s, curset->cur + 1);
      return (NULL);
    }
  return (tab);
}

static int	fill_str(t_comp *str, t_curset *curset)
{
  if ((str->new = get_new(curset->s, curset->cur)) == NULL)
    return (-1);
  if ((str->end = get_end(curset->s, curset->cur)) == NULL)
    return (-1);
  if ((str->start = get_start(curset->s,
			     curset->cur, my_strlen(str->new))) == NULL)
    return (-1);
  return (0);
}

int		call_completion(t_curset *curset)
{
  int		i;
  char		**tab;
  t_comp	str;

  i = 0;
  if (fill_str(&str, curset) == -1)
    return (-1);
  if ((tab = load_or_return(str.new, curset)) == NULL)
    return (-1);
  while (curset->ch == '\t' && tab[i] != NULL)
    {
      curset->ch = 0;
      free(curset->s);
      curset->s = my_catalloc(str.start, tab[i], str.end);
      curset->cur = my_strlen(curset->s);
      print_cur(curset->cur, curset->s);
      if (tab[i + 1] != NULL)
	read(0, &curset->ch, 1);
      i++;
    }
  free_tab(tab);
  free_tcomp(&str);
  return (0);
}
