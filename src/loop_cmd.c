/*
** loop_cmd.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 21 15:07:47 2017 Léandre Blanchard
** Last update Sun May 21 17:16:19 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include "my.h"

static char	**check_loop(t_env *my_env, t_list_al *alias)
{
  char		**cmds;

  if (recreate_env(&(my_env->env)) == 1)
    return (NULL);
  if ((cmds = update_from_file(PATH_HISTORY)) == NULL)
    return (NULL);
  if (init_alias(alias) == 1)
    return (NULL);
  return (cmds);
}

int		loop(t_env *my_env, t_info *list)
{
  char          *ln;
  char          **cmds;
  t_list_al     alias;

  if ((cmds = check_loop(my_env, &alias)) == NULL)
    return (-1);
  ln = NULL + 1;
  while (ln != NULL)
    {
      if ((ln = source_cmd(cmds)) == NULL)
	break;
      if ((ln  = replace_alias(ln, &alias)) == NULL)
	return (-1);
      if (ln != NULL && ln[0] != 0)
	{
	  if ((my_env->ret = (my_parse(list, ln))) == -1)
	    return (84);
	  parse_loop(list, list->first, my_env, &alias);
	}
      save_cmd(ln);
      cmds = tab_append(cmds, ln);
    }
  free_alias(&alias);
  free_tab(cmds);
  return (0);
}
