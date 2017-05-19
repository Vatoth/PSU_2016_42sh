/*
** my_strlen.c for task04 in /home/TomicNikola/CPool_Day04
**
** Made by Nikola Tomic
** Login   <TomicNikola@epitech.net>
**
** Started on  Thu Oct  6 09:06:37 2016 Nikola Tomic
** Last update Wed Mar 01 23:46:02 2017 nikola.tomic@epitech.eu
*/

int	my_strlen(char *str)
{
  int	inc;

  if (!str)
    return (-1);
  inc = 0;
  while (str[inc] != '\0')
    inc++;
  return (inc);
}
