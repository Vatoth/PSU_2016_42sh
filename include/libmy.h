/*
** libmy.h for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 21 16:51:18 2017 Léandre Blanchard
** Last update Sun May 21 19:37:21 2017 Antoine
*/

#ifndef LIBMY_H_
# define LIBMY_H_

int		my_tablen(char **tab);
int		my_printf(const char *format, ...);
void		my_put_tabw(const char *first,
			    char **tab,
			    const char *last);
char		*my_calloc(int size);
int		my_strlen(const char *s);
char		*my_strcpy(char *dest, const char *src);
char		*my_strncpy(char *dest,
			    const char *src,
			    int len);
int		epur_str(char *str);
char		**tab_append(char **prev, char *add);
char		*my_catalloc(const char *s,
			     const char *s_1,
			     const char *s_2);
int		my_revstr(char *s);
int		nb_of(const char *s, char cmp);
void		free_tab(char **tab);
void		my_putchar(char c);
void		my_putstr(const char *s);
char		*my_strcat(char *dest, char *src);
int		my_strcmp(char *s1, char *s2);
int		my_strlen(const char *str);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strstr(char *str, char *to_find);
char		*my_strcpy(char *dest, const char *src);
char		*my_strncpy(char *dest, const char *src, int len);
char		*my_strdup(const char *src);
char		*get_next_line(const int fd);
void		my_putnbr(int nb);
void		zeros(char *s, int size);

#endif /* LIBMY_H_ */
