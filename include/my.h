/*
** my.h for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2/include
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Mon Apr 03 16:50:44 2017 nikola.tomic@epitech.eu
** Last update Fri May 19 22:04:58 2017 
*/

#ifndef MY_H_
# define MY_H_
# define LEFT	0
# define RIGHT	1
# define MIN_SIZE 10

# include "colors.h"

typedef struct	s_list
{
  char		*var;
  struct s_list	*next;
}		t_list;

typedef struct		s_btree
{
  char			*cmd;
  int			*pp;
  struct s_btree	*parent;
  struct s_btree	*left;
  struct s_btree	*right;
}			t_btree;

typedef struct          s_parse
{
  char                  *line;
  char                  token;
  struct s_parse        *next;
  struct s_parse	*prev;
}                       t_parse;

typedef struct          s_info
{
  int                   i;
  struct s_parse        *first;
  struct s_parse	*last;
}                       t_info;

int		recreate_env(t_list **dupenvp);
char		*my_frealloc(char *s, int size);
void		my_put_tab(char **tab);
void		my_put_tabw(const char *start,
			    char **tab, const char *end);
int		my_tablen(char **tab);
char		**tab_append(char **prev, char *add);
char		**update_from_file(const char *filename);
int		save_cmd(const char *cmd);
int		nb_of(const char *s, char c);
int		routine_ioctl(void);
char		*my_calloc(int size);
char		*get_cmd(char **cmds);
char		*add_color(char *cmd);
int		mainloop(t_list *dupenv, int *ret);
int		my_printf(const char *format, ...);
void		my_clear(void);
void		sigint_handler(int sig);
char		*my_catalloc(const char *s, const char *s_1,
			     const char *s_2);
int		my_revstr(char *s);
void		shift_left(char *s, int nb);
void		shift_right(char *s, int nb);
void		display_list(t_list *list);
int		remove_node(t_list **list, t_list *node);
t_list		*put_in_list(t_list **list, char *var);
int		via_pipe(int *ret);
t_list		*tab_to_list(char **tab);
char		**list_to_tab(t_list *list);
char		*my_get_var(t_list *list, char *var);
int		my_unsetenv(t_list **dupenvp, char *arg);
int		my_setenv(t_list **dupenvp, char *var, char *value);
int		my_cd(t_list **dupenvp, char *arg);
void		free_tab(char **tab);
void		free_list(t_list *list);
char		*find_path(t_list *dupenvp, char *cmd);
void		my_putchar(char c);
int		my_putstr(char *str);
int		list_len(t_list *list);
char		**my_str_to_wordtab(char *str, char *seps);
char		*my_strcat(char *dest, char *src);
int		my_strcmp(char *s1, char *s2);
int		my_strlen(char *str);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strstr(char *str, char *to_find);
char		*my_strcpy(char *dest, char *src);
char		*my_strdup(char *src);
char		*get_next_line(const int fd);
int		my_str_isalnum(char *str);
int		my_isalnum(char c);
int		my_error(char *cmd, char *msg, int ret);
void		disp_prompt(void);
int		builtins(char *cmd, t_list **dupenvp, int *ret);
char		*my_strip(char *str, char *to_strip);
char		*redirections(char *cmd);
int		tab_len(char **tab);
t_btree		*make_tree(char **tab);
int		my_pipes(char *cmd, int *ret, t_list **dupenvp);
t_btree		*get_outermost(t_btree *tree, char side);
int		execution(char *cmd, t_list *dupenvp, int *ret);
void		my_putnbr(int nb);
void		check_status(int *ret);
void		free_tree(t_btree *tree);
void		my_heredoc(int pp[2], char *file);
char		*add_spaces(char *str);
void            clear_list(t_info *list);
int		epur_str(char *str);
int		my_parse(t_info *list, char *s);
void		my_free(void *ptr);
int		explore(t_info *list);
int		my_str_isascii(char *str);
int		my_echo(char *str);

#endif /* !MY_H_ */
