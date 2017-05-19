/*
** my_isalnum.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Apr 04 19:35:25 2017 nikola.tomic@epitech.eu
** Last update Tue Apr 04 19:38:21 2017 nikola.tomic@epitech.eu
*/

int	my_isalnum(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9') || c == '_')
    return (1);
  return (0);
}
