/*
** my.h for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2/include
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Mon Apr 03 16:50:44 2017 nikola.tomic@epitech.eu
** Last update Sun May 21 23:00:42 2017 Léandre Blanchard
*/

#ifndef MY_H_
# define MY_H_
# define LEFT	0
# define RIGHT	1
# define MIN_SIZE 10
# define PATH_HISTORY "/.42sh_history"
# define PATH_RC "/.42shrc"
# define VAR_PATH "PATH"
# define VAR_USER "USER"
# define ALIAS "alias"
# define COLORS_LS " --color=yes"

# include "colors.h"
# include "libmy.h"

typedef struct		s_alias
{
  char			*alias;
  char			*cmd;
  struct s_alias	*next;
  struct s_alias	*prev;
}                       t_alias;

typedef struct		s_list_al
{
  char			**file;
  struct s_alias	*first;
  struct s_alias	*last;
}			t_list_al;

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

typedef struct		s_parse
{
  char			*line;
  char			token;
  struct s_parse	*next;
  struct s_parse	*prev;
}                       t_parse;

typedef struct		s_info
{
  int			i;
  struct s_parse	*first;
  struct s_parse	*last;
}			t_info;

typedef struct		s_env
{
  t_list		*env;
  int			ret;
}			t_env;

int		init_alias(t_list_al *alias);
int		loop(t_env *my_env, t_info *list);
int		check_env(t_list *dupenvp, char *var);
char		*source_cmd(char **cmds);
int		preparation(char *cmd,
			    t_env *my_env, t_list_al *alias);
int		parse_loop(t_info *list, t_parse *shell,
			   t_env *my_env, t_list_al *alias);
int		recreate_env(t_list **dupenvp);
int		recreate_path(t_list **dupenvp, char *s);
char		*my_frealloc(char *s, int size);
void		my_put_tab(char **tab);
void		my_put_tabw(const char *start,
			    char **tab, const char *end);
char		**update_from_file(const char *filename);
int		my_count(char *str, char c);
int		save_cmd(const char *cmd);
int		routine_ioctl(void);
char		*my_calloc(int size);
char		*get_cmd(char **cmds);
char		*add_color(char *cmd);
int		mainloop(t_env *my_env);
int		add_alias(t_list_al *alias,
			  char *new, char *cmd);
void		sigint_handler(int sig);
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
void		free_list(t_list *list);
char		*find_path(t_list *dupenvp, char *cmd);
int		list_len(t_list *list);
char		**my_str_to_wordtab(char *str, char *seps);
int		my_str_isalnum(char *str);
int		my_isalnum(char c);
int		my_error(char *cmd, char *msg, int ret, int fd);
void		disp_prompt(void);
int		builtins(char *cmd, t_env *my_env, t_list_al *alias);
char		*my_strip(char *str, char *to_strip);
char		*redirections(char *cmd);
t_btree		*make_tree(char **tab);
int		my_pipes(char *cmd, t_env *my_env,
			 t_list_al *alias);
t_btree		*get_outermost(t_btree *tree, char side);
int		execution(char *cmd, t_env *my_env, int fd);
void		check_status(int *ret);
void		free_tree(t_btree *tree);
char		*add_spaces(char *str);
void		clear_list(t_info *list);
int		my_parse(t_info *list, char *s);
void		my_free(void *ptr);
int		explore(t_info *list);
int		my_str_isascii(char *str);
int		my_echo(char *str);
int		is_pipable(char *cmd);
int		check_cmds(char **tab, int *ret, char *cmd);
char		*replace_alias(char *cmd, t_list_al *alias);
int		unalias(t_list_al *alias, char *cmd);
void		free_alias(t_list_al *alias);
int		check_ambigus(const char *s);
int		take_argument(t_info *list, char *s,
				      const char token,
				      const int a);
int		parse_and(t_info *list, char *s,
			  int *a, int *rest);
int		my_parse_continue(t_info *list, char *s,
				  int *a, int *rest);
int		check_simple_quote(const char *s, int *i);

#endif /* !MY_H_ */
