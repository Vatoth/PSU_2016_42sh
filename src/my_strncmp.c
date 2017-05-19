/*
** my_strncmp.c for task07 in /home/TomicNikola/CPool_Day06
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Mon Oct 10 12:55:56 2016 Nikola Tomic
** Last update Wed Mar 01 23:54:44 2017 nikola.tomic@epitech.eu
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && i < n)
    i = i + 1;
  if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
    return (0);
  return (s1[i] - s2[i]);
}
