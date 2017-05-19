/*
** my_putchar.c for my_putchar in /home/lblanchard/CPool_Day07/lib/my/libmy
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Oct 11 10:36:32 2016 Leandre Blanchard
** Last update Fri Feb 24 16:34:28 2017 Léandre Blanchard
*/

#include <unistd.h>

void	my_putchar(int c)
{
  write(1, &c, 1);
}
