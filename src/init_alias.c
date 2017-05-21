/*
** init_alias.c for  in /home/vatoth/Epitech/PSU_2016_42sh/src
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sun May 21 15:48:39 2017 
** Last update Sun May 21 16:16:00 2017 
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

static void	protect_alias(char *s)
{
  int		i;

  i = 0;
  while (s != NULL && s[i] != '\0')
    {
      if (s[i] == '"')
        {
          i++;
          while (s[i] != '\0' && s[i] != '"')
            {
              if (s[i] == ' ')
		s[i] = -1;
              i++;
            }
        }
      i++;
    }
}

static int	count_quote(const char *s)
{
  int		i;
  int		quote;

  i = 0;
  quote = 0;
  while (s[i] != '\0')
    {
      if (s[i] == '"')
	quote++;
      i++;
    }
  return (quote);
}

static int		init_list(t_list_al *alias)
{
  alias->first = NULL;
  alias->last = NULL;
  if ((alias->file = update_from_file(PATH_RC)) == NULL)
    return (1);
  return (0);
}

int		init_alias(t_list_al *alias)
{
  char		**tab;
  char		*s;
  int		i;

  if (init_list(alias) == 1)
    return (1);
  i = -1;
  while (alias->file[++i] != NULL)
    {
      if (strncmp(alias->file[i], ALIAS, 5) == 0 &&
          (count_quote(alias->file[i]) == 2 || !count_quote(alias->file[i])))
        {
          if ((s = strdup(alias->file[i])) == NULL)
            return (1);
          protect_alias(s);
          if ((tab = my_str_to_wordtab(s, " ")) == NULL)
            return (1);
          if (my_tablen(tab) == 3 && count_quote(tab[1]) == 0)
            if (add_alias(alias, tab[1], tab[2]) == -1)
              return (1);
          free(s);
          free_tab(tab);
	}
    }
  return (0);
}
