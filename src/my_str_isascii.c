/*
** my_str_isascii.c for 42sh in /home/leandre/System_unix/PSU_2016_42sh
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 21 14:50:35 2017 Léandre Blanchard
** Last update Sun May 21 14:50:45 2017 Léandre Blanchard
*/

int     my_str_isascii(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < 20)
	return (1);
      i++;
    }
  return (0);
}
