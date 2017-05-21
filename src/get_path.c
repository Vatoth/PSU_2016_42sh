/*
** get_path.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 20 14:41:49 2017 Léandre Blanchard
** Last update Sat May 20 14:42:00 2017 Léandre Blanchard
*/

#include "42sh_history.h"

char            *get_path(const char *filename)
{
  char          *name;

  name = getenv(USERNAME);
  if ((name = my_catalloc(ABSOLUTE_HOME, name, filename)) == NULL)
    return (NULL);
  return (name);
}
