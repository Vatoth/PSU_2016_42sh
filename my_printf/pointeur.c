/*
** pointeur.c for pointeru in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Nov  9 19:06:51 2016 Leandre Blanchard
** Last update Sun Apr 30 17:13:35 2017 Léandre Blanchard
*/

#include "my_printf.h"

void	pointeur(void *i)
{
  my_putstr("0x");
  my_put_pointer((unsigned long long)i);
}
