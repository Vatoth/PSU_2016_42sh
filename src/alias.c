/*
** alias.c for  in /home/vatoth/Epitech/PSU_2016_42sh
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Fri May 19 17:08:22 2017 
** Last update Fri May 19 22:40:52 2017 
*/

#include <string.h>

typedef struct	s_alias
{
  char		*alias;
  char		*cmd;
  struct s_list	*next;
}		t_alias;

typedef struct	s_list_al
{
  char		**file;
  struct s_list	*first;
}		t_list_al;


int		replace_alias(char *cmd, t_list_al *alias)
{
  int		i;
  t_alias	tmp;
  char		*new_cmd;

  i = 0;
  tmp = alias->first;
  new_cmd = cmd;
  while (alias->next)
    {
      if (strncmp(cmd, tmp->alias, strlen(tmp->alias)) == 0)
	{
	  if (cmd[strlen(tmp->alias)] == '\0' || cmd[strlen(tmp->alias)] == ' ')
	    {
	      if ((new_cmd = my_strcat(alias, &cmd[strlen(alias)]) != NULL))
		{
		  free(cmd);
		  return (new_cmd);
		}
	      else
		return (NULL);
	    }
	  
	}
    }
  return (new_cmd);
}
