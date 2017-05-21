/*
** routine.h for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 17 13:46:07 2017 Léandre Blanchard
** Last update Sat May 20 22:26:43 2017 Léandre Blanchard
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

char		*get_new(char *s, int cur);
char		*get_end(char *s, int cur);
char		*get_start(char *s, int cur, int size);
void		free_tab(char **tab);
char		*my_catalloc(const char *first, const char *second,
			     const char *third);
int		epur_str(char *s);
int		call_completion(t_curset *curset);
void		move_and_add(char *s, int cur, char ch);
void		move_and_ret(char *s, int cur);
void		new_hist(t_curset *curset, int dir);
char		*my_frealloc(char *s, int size);
void		print_cur(int cur, char *s);
void		zeros(char *s, int size);
int             my_tablen(char **tabl);
void		shift_right(char *s, int size);
void		shift_left(char *s, int size);
void		my_clear(void);
void		disp_prompt(void);
int		my_printf(const char *format, ...);
char		*my_calloc(int size);
char		*my_strcpy(char *dest, const char *src);
int		my_strlen(const char *s);
char		*get_next_line(int fd);
void		backspace(void);
int		ret_back(t_curset *curset);
int		left_key(t_curset *curset);
void		free_tcomp(t_comp *str);
int		right_key(t_curset *curset);
int		up_key(t_curset *curset);
int		down_key(t_curset *curset);
int		cur_end(t_curset *curset);
int		cur_home(t_curset *curset);
int		ctrl_d(t_curset *curset);
int		ctrl_l(t_curset *curset);
char		**glob_tab(const char *s);
int		alt_l(t_curset *curset);
int		ctrl_c(t_curset *curset);
void		move_and_add(char *s, int cur, char ch);
int		ctrl_k(t_curset *curset);
char		*my_strdup(const char *s);

#endif /* !ROUTINE_H_ */
