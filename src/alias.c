/*
** alias.c for  in /home/vatoth/PSU_2016_42sh
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat May 20 13:14:10 2017 
** Last update Sun May 21 10:21:53 2017 
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <my.h>

void		restore_alias(t_alias *new_element)
{
  int		i;

  i = -1;
  while (new_element->cmd[++i] != '\0')
    {
      if (new_element->cmd[0] == '"')
	new_element->cmd[0] = ' ';
      if (new_element->cmd[i] == -1)
	new_element->cmd[i] = ' ';
    }
  if (strlen(new_element->cmd) > 0)
    {
      if (new_element->cmd[strlen(new_element->cmd) - 1] == '"')
	new_element->cmd[strlen(new_element->cmd) - 1] = ' ';
    }
}

int		add_alias(t_list_al *alias, char *new, char *cmd)
{
  t_alias	*new_element;

  if ((alias != NULL) && (cmd != NULL))
    {
      if (((new_element = malloc(sizeof(t_alias))) == NULL)
	  || ((new_element->alias = strdup(new)) == NULL)
	  || ((new_element->cmd = strdup(cmd)) == NULL))
	return (-1);
      restore_alias(new_element);
      epur_str(new_element->cmd);
      new_element->next = alias->first;
      new_element->prev = NULL;
      if (alias->first)
	alias->first->prev = new_element;
      else
	alias->last = new_element;
      alias->first = new_element;
    }
  return (0);
}

int             del_alias(t_list_al *alias, t_alias *element)
{
  if (element->next == NULL && element->prev == NULL)
    return (0);
  else if (element->next == NULL)
    {
      alias->last = element->prev;
      alias->last->next = NULL;
    }
  else if (element->prev == NULL)
    {
      alias->first = element->next;
      alias->first->prev = NULL;
    }
  else
    {
      element->next->prev = element->prev;
      element->prev->next = element->next;
    }
  free(element);
  return (0);
}

int		unalias(t_list_al *alias, char *cmd)
{
  t_alias	*tmp;

  tmp = alias->first;
  while (tmp && cmd != NULL)
    {
      if (strcmp(cmd, tmp->alias) == 0)
	del_alias(alias, tmp);
      tmp = tmp->next;
    }
  return (0);
}


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
	      if (((new_cmd = my_catalloc(tmp->cmd,
					 &cmd[strlen(tmp->alias)],
					  NULL)) != NULL))
		{
		  free(cmd);
		  return (new_cmd);
		}
	      else
		return (NULL);
	    }
	}
      tmp = tmp->next;
    }
  return (new_cmd);
}
