/*
** char_to_nchar.c for char_to_nchar in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 21:48:25 2016 Leandre Blanchard
** Last update Sun Apr 30 16:43:07 2017 Léandre Blanchard
*/

#include "my.h"
#include "my_printf.h"

char    *char_to_nchar(va_list va, int n)
{
  char  *str;
  char  *va_cpy;

  va_cpy = my_strdup(va_arg(va, char *));
  if (n > my_strlen(va_cpy))
    n = my_strlen(va_cpy);
  if ((str = malloc(sizeof (char) * n + 1)) == NULL)
    return (NULL);
  my_strncpy(str, va_cpy, n);
  return (str);
}
