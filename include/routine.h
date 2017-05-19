/*
** routine.h for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 17 13:46:07 2017 Léandre Blanchard
** Last update Fri May 19 19:10:44 2017 Léandre Blanchard
*/

#ifndef ROUTINE_H_
# define ROUTINE_H_

# include <sys/ioctl.h>
# include <termios.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>

# define NB_PTR 11

typedef struct	s_curset
{
  int		cur;
  int		hist;
  char		*s;
  char		**cmds;
  char		ch;
  int		i;
}		t_curset;

char		*my_frealloc(char *s, int size);
void		print_cur(int cur, char *s);
void		zeros(char *s, int size);
int             my_tablen(char **tabl);
void		shift_right(char *s, int size);
void		my_clear(void);
void		disp_prompt(void);
int		my_printf(const char *format, ...);
char		*my_calloc(size_t size);
char		*my_strcpy(char *dest, char *src);
int		my_strlen(char *s);
char		*get_next_line(int fd);
void		backspace(char *s);
int		ret_back(t_curset *curset);
int		left_key(t_curset *curset);
int		right_key(t_curset *curset);
int		up_key(t_curset *curset);
int		down_key(t_curset *curset);
int		cur_end(t_curset *curset);
int		cur_home(t_curset *curset);
int		ctrl_d(t_curset *curset);
int		ctrl_l(t_curset *curset);
int		alt_l(t_curset *curset);
int		ctrl_c(t_curset *curset);
int		ctrl_k(t_curset *curset);

#endif /* !ROUTINE_H_ */
