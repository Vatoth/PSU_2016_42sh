/*
** builtins.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Apr 04 12:44:19 2017 nikola.tomic@epitech.eu
** Last update Sun May 21 14:57:50 2017 Quentin Sonnefraud
*/

#include <unistd.h>
#include <wordexp.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "define.h"

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
      my_printf("%s%s", ERROR_ENV, ERRENV);
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
    new_dir = my_get_var(*dupenvp, VAR_HOME);
  else if (my_strlen(arg) == 1 && arg[0] == '-')
    new_dir = my_get_var(*dupenvp, VAR_OLDPWD);
  else
    new_dir = (arg[0] == '~') ?
      my_strcat(my_get_var(*dupenvp, VAR_HOME), &arg[1]) : arg;
  old_dir = getcwd(NULL, 0);
  if (chdir(new_dir) == -1)
    {
      write(2, new_dir, my_strlen(new_dir));
      write(2, NOT_DIRECTORY, my_strlen(NOT_DIRECTORY));
      return (1);
    }
  else
    {
      my_setenv(dupenvp, VAR_OLDPWD, old_dir);
      my_setenv(dupenvp, VAR_PWD, getcwd(NULL, 0));
    }
  return (0);
}

int		base_builtins(char **args, t_env *my_env,
			      t_list_al *alias, wordexp_t p)
{
  if (my_strcmp(args[0], EXIT) == 0)
    {
      wordfree(&p);
      free_list(my_env->env);
      free_alias(alias);
      exit(my_env->ret);
    }
  else if (my_strcmp(args[0], ENV) == 0)
    display_list(my_env->env);
  else if (my_strcmp(args[0], SETENV) == 0)
    my_env->ret = my_setenv(&(my_env->env), args[1], args[2]);
  else if (my_strcmp(args[0], UNSETENV) == 0)
    my_unsetenv(&(my_env->env), args[1]);
  else if (my_strcmp(args[0], CD) == 0)
    my_env->ret = my_cd(&(my_env->env), args[1]);
  else if (my_strcmp(args[0], ALIAS) == 0 && (args[1] != NULL))
    my_env->ret = add_alias(alias, args[1], args[2]);
  else if (my_strcmp(args[0], UNALIAS) == 0)
    unalias(alias, args[1]);
  else
    return (1);
  return (0);
}

int		builtins(char *cmd, t_env *my_env,
			 t_list_al *alias)
{
  char		**args;
  wordexp_t	p;

  if ((wordexp(cmd, &p, 0)) != 0 || (args = p.we_wordv) == NULL)
    return (0);
  if (base_builtins(args, my_env, alias, p) == 0)
    {
      wordfree(&p);
      return (1);
    }
  else if (args[1] != NULL && my_strcmp(args[0], MY_ECHO) == 0
	   && my_strcmp(args[1], "$?") == 0)
    my_printf("%d\n", my_env->ret);
  else if (my_strcmp(args[0], MY_ECHO) == 0)
    my_echo(cmd);
  else
    {
      wordfree(&p);
      return (0);
    }
  wordfree(&p);
  return (1);
}
