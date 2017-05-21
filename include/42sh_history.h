/*
** 42sh_history.h for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 17 18:09:04 2017 Léandre Blanchard
** Last update Sun May 21 19:25:39 2017 Antoine
*/

#ifndef SH_HISTORY_H_
# define SH_HISTORY_H_

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define PATH_HISTORY "/.42sh_history"
# define MASSIVE 100000
# define WARNING_MASSIVE "[WARNING] ~/.42sh_history file supersized !\n"
# define ONLY_LASTS "Loading only last 1000 commands\n"
# define ISSUE_SAVE "Can't access ~/.42sh_history\n"
# define USERNAME "USER"
# define ABSOLUTE_HOME "/home/"

typedef struct	s_tab
{
  char		**array;
  int		nb;
  int		i;
  int		y;
  int		k;
}		t_tab;

char		*get_path(const char *filename);
char		**basic_wordtab(const char *s, int no);
char		*my_calloc(int size);
char		**my_str_to_wordtab(const char *s, int no);
int		my_printf(const char *format, ...);
int		nb_of(const char *s, char cmp);
void		shift_right(char *s, int nb);
int		my_strlen(const char *s);
char		*my_catalloc(const char *first,
			     const char *second, const char *third);

#endif /* !SH_HISTORY_H_ */
