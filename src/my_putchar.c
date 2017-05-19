/*
** my_putchar.c for my_putchar in /home/TomicNikola/CPool_Day10/lib/my
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Mon Oct 17 14:01:32 2016 Nikola Tomic
** Last update Fri Nov 11 14:13:25 2016 Nikola Tomic
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
