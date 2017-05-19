/*
1;4803;0c** alias.c for  in /home/vatoth/Epitech/PSU_2016_42sh
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Fri May 19 17:08:22 2017 
** Last update Fri May 19 22:56:56 2017 
*/

#include <string.h>
#include <stdlib.h>
#include <my.h>

typedef struct		s_alias
{
  char			*alias;
  char			*cmd;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_list_al
{
  char			**file;
  struct s_alias	*first;
}			t_list_al;

char		*replace_alias(char *cmd, t_list_al *alias)
{
  t_alias	*tmp;
  char		*new_cmd;

  tmp = alias->first;
  new_cmd = cmd;
  while (tmp)
    {
      if (strncmp(cmd, tmp->alias, strlen(tmp->alias)) == 0)
	{
	  if (cmd[strlen(tmp->alias)] == '\0' ||
	      cmd[strlen(tmp->alias)] == ' ')
	    {
	      if (((new_cmd = my_catalloc(tmp->alias,
					 &cmd[strlen(tmp->alias)],
					  NULL)) != NULL))
		{
		  free(cmd);
		  return (new_cmd);
		}
	      else
		return (NULL);
	    }
	  tmp = tmp->next;
	}
    }
  return (new_cmd);
}
