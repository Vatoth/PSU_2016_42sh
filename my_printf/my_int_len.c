/*
** my_int_len.c for int_len in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb 24 21:06:27 2017 Léandre Blanchard
** Last update Thu Mar 23 13:09:34 2017 Léandre Blanchard
*/

int		my_intlen(int nb)
{
  int		i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}
