/*
** routine.h for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 17 13:46:07 2017 Léandre Blanchard
** Last update Sun May 21 23:00:50 2017 Léandre Blanchard
*/

#ifndef ROUTINE_H_
# define ROUTINE_H_

# include <sys/ioctl.h>
# include <termios.h>
# include <stdlib.h>
# include <string.h>
# include <glob.h>
# include <unistd.h>

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

typedef struct	s_comp
{
  char		*start;
  char		*new;
  char		*end;
}		t_comp;

void		print_cur(int cur, char *s);
void		move_and_add(char *s, int cur, char ch);
int		call_completion(t_curset *curset);
void		new_hist(t_curset *curset, int dir);
char		*my_frealloc(char *s, int size);
void		shift_right(char *s, int size);
void		shift_left(char *s, int size);
void		disp_prompt(void);
void		backspace(void);
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
