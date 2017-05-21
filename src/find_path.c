/*
** find_path.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Apr 04 14:19:19 2017 nikola.tomic@epitech.eu
** Last update Sun May 21 15:35:24 2017 
*/

#include <unistd.h>
#include <stdlib.h>
#include "define.h"
#include "my.h"

char	*find_path(t_list *dupenvp, char *cmd)
{
  char	**tab;
  char	*tmp;
  int	i;

  if (!cmd || my_strstr(cmd, "/"))
    return (NULL);
  tab = my_str_to_wordtab(my_get_var(dupenvp, VAR_PATH), ":");
  i = 0;
  while (tab && tab[i])
    {
      tmp = tab[i];
      if (tmp[my_strlen(tmp) - 1] != '/')
	{
	  if (!(tmp = my_strcat(tmp, "/")))
	    return (NULL);
	}
      if (access(my_strcat(tmp, cmd), X_OK) == 0)
	return (tmp);
      i += 1;
    }
  return (NULL);
}
