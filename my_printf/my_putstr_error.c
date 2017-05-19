/*
** my_pustr_error.c for my_put_str_error in /home/lblanchard/CPool_infinadd
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Oct 25 09:16:42 2016 Leandre Blanchard
** Last update Sun Apr 30 17:23:36 2017 Léandre Blanchard
*/

#include "my.h"

void	my_putstr_error(const char *str)
{
  write(2, str, my_strlen(str));
}
