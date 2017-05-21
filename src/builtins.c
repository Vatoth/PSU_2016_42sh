/*
** builtins.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Apr 04 12:44:19 2017 nikola.tomic@epitech.eu
** Last update Sun May 21 10:17:36 2017 
*/

#include <unistd.h>
#include <wordexp.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int		my_unsetenv(t_list **dupenvp, char *arg)
{
  t_list	*tmp;
  char		*cpy;

  if (!arg || !(cpy = my_strcat(arg, "=")))
    return (1);
  tmp = *dupenvp;
  while (tmp && my_strncmp(tmp->var, cpy, my_strlen(cpy)) != 0)
    tmp = tmp->next;
  if (!tmp)
    return (0);
  remove_node(dupenvp, tmp);
  return (1);
}

int		my_setenv(t_list **dupenvp, char *var, char *value)
{
  t_list	*tmp;
  char		*cpy;

  if (!var)
    display_list(*dupenvp);
  if (!(cpy = my_strcat(var, "=")))
    return (0);
  if (my_str_isalnum(var) == 0)
    {
      my_putstr("setenv: Variable name must "
		"contain alphanumeric characters.\n");
      return (1);
    }
  tmp = *dupenvp;
  while (tmp && my_strncmp(tmp->var, cpy, my_strlen(cpy)) != 0)
    tmp = tmp->next;
  if (!tmp)
    {
      if (!(put_in_list(dupenvp, my_strcat(cpy, value))))
	  return (0);
    }
  else
    if (!(tmp->var = my_strcat(cpy, value)))
      return (0);
  return (0);
}

int	my_cd(t_list **dupenvp, char *arg)
{
  char	*new_dir;
  char	*old_dir;

  if (!arg)
    new_dir = my_get_var(*dupenvp, "HOME");
  else if (my_strlen(arg) == 1 && arg[0] == '-')
    new_dir = my_get_var(*dupenvp, "OLDPWD");
  else
    new_dir = (arg[0] == '~') ?
      my_strcat(my_get_var(*dupenvp, "HOME"), &arg[1]) : arg;
  old_dir = getcwd(NULL, 0);
  if (chdir(new_dir) == -1)
    {
      my_putstr(new_dir);
      my_putstr(": Not a directory.\n");
      return (1);
    }
  else
    {
      my_setenv(dupenvp, "OLDPWD", old_dir);
      my_setenv(dupenvp, "PWD", getcwd(NULL, 0));
    }
  return (0);
}

int		builtins(char *cmd, t_env *my_env,
			 t_list_al *alias)
{
  char		**args;
  wordexp_t	p;

  if ((wordexp(cmd, &p, 0)) != 0 || (args = p.we_wordv) == NULL)
    return (0);
  if (my_strcmp(args[0], "exit") == 0)
    {
      wordfree(&p);
      free_list(my_env->env);
      free_alias(alias);
      exit(my_env->ret);
    }
  else if (my_strcmp(args[0], "env") == 0)
    display_list(my_env->env);
  else if (my_strcmp(args[0], "setenv") == 0)
    my_env->ret = my_setenv(&(my_env->env), args[1], args[2]);
  else if (my_strcmp(args[0], "unsetenv") == 0)
    my_unsetenv(&(my_env->env), args[1]);
  else if (my_strcmp(args[0], "cd") == 0)
    my_env->ret = my_cd(&(my_env->env), args[1]);
  else if (my_strcmp(args[0], "alias") == 0 && (args[1] != NULL))
    my_env->ret = add_alias(alias, args[1], args[2]);
  else if (my_strcmp(args[0], "unalias") == 0)
    unalias(alias, args[1]);
  else if (args[1] != NULL && my_strcmp(args[0], "echo") == 0
	   && my_strcmp(args[1], "$?") == 0)
    my_printf("%d\n", my_env->ret);
  else if (my_strcmp(args[0], "echo") == 0)
    my_echo(cmd);
  else
    {
      wordfree(&p);
      return (0);
    }
  wordfree(&p);
  return (1);
}
