/*
** nb_arg.c for nb_arg in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 21:15:26 2016 Leandre Blanchard
** Last update Sun Apr 30 17:25:14 2017 Léandre Blanchard
*/

#include "my.h"

int     nb_arg(const char *format, int i)
{
  char  *part;
  int   len;

  part = malloc(sizeof (char) * my_strlen(format) + 1);
  if (part == NULL)
    return (-1);
  my_strncpy(part, format, i);
  len = my_strlen(my_strdup(int_to_char(my_getnbr(part)))) + 3;
  return (len);
}
