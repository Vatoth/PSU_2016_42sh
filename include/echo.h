/*
** echo.h for echo.h in /home/homegan/projects/PSU_2016_42sh
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Sat May 20 16:37:31 2017 Antoine
** Last update Sat May 20 17:01:28 2017 Antoine
*/

#ifndef ECHO_H_
# define ECHO_H_

typedef struct  s_sp_car
{
  char          name;
  char          corresp;
}               t_sp_car;

typedef struct  s_echo_flag
{
  int           without_return;
  int           args;
  int           print_sp;
  int           printed;
  int           index_flag;
  int           index_tab;
}               t_sp_flag;

typedef struct  s_sp_fcts
{
  char          name;
  int           (*fct)(t_sp_flag *);
}               t_sp_fcts;

void	fullfill_sp_tab(t_sp_car sp_tab[10]);
int	my_putstr_without_sp(char *c);
int	echo_without_n(t_sp_flag *var);
int	with_backslash(t_sp_flag *var);
int	without_backslash(t_sp_flag *var);

#endif /* !ECHO_H_ */
