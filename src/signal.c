/*
** signal.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon May 15 13:58:17 2017 Léandre Blanchard
** Last update Sun May 21 22:58:36 2017 Léandre Blanchard
*/

#include <signal.h>
#include "my.h"

void		sigint_handler(int signo)
{
  if (signo == SIGINT)
    {
      my_printf("\n");
      disp_prompt();
    }
}
