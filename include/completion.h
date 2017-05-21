/*
** completion.h for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 21 16:04:03 2017 Léandre Blanchard
** Last update Sun May 21 19:27:31 2017 Antoine
*/

#ifndef COMPLETION_H_
# define COMPLETION_H_

#include <stdlib.h>
#include <glob.h>
#include <string.h>
#include <unistd.h>
#include "routine.h"
#include "libmy.h"

char		*get_new(char *s, int cur);
char		*get_end(char *s, int cur);
char		*get_start(char *s, int cur, int size);
char		**glob_tab(const char *s);
void		free_tcomp(t_comp *str);
void		move_and_ret(char *s, int cur);

#endif /* !COMPLETION_H_ */
