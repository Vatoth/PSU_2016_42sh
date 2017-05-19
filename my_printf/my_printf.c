/*
** my_printf.c for my_printf in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 20:02:36 2016 Leandre Blanchard
** Last update Sun Apr 30 17:26:03 2017 Léandre Blanchard
*/

#include "my.h"
#include "my_printf.h"

int    normal_print(int c, va_list va)
{
  if (c != 'c' && c != 's' && c != 'd'
            && c != 'u' && c != 'o' && c != 'b'
            && c != 'S' && c != 'p' && c != 'x'
      && c != 'i' && c != 'D' && c != 'U' && c != 'O'
      && c != 'X' && c != 'f')
    {
      my_putstr_error("Invalid argument beside '%' in my_printf function\n");
      return (84);
    }
  (c == 'c') ? my_putchar(va_arg (va, int)) : c;
  (c == 's') ? my_putstr(va_arg (va, char *)) : c;
  (c == 'd' || c == 'u' || c == 'U'
   || c == 'D' || c == 'i') ? my_put_nbr(va_arg (va, long long)) : c;
  (c == 'o') ? my_putnbr_base(va_arg (va, long long), "01234567") : c;
  (c == 'O') ? my_putnbr_base(va_arg (va, long long), "01234567") : c;
  (c == 'b') ? my_putnbr_base(va_arg (va, long long), "01") : c;
  (c == 'S') ? conv_to_printable(va_arg(va, char *)) : c;
  (c == 'p') ? pointeur(va_arg (va, void *)) : c;
  (c == 'x') ? my_putnbr_base(va_arg (va, long long), "0123456789abcdef") : c;
  (c == 'X') ? my_putnbr_base(va_arg (va, long long), "0123456789ABCDEF") : c;
  (c == 'f') ? my_put_float(va_arg (va, double)) : c;
  return (0);
}

int	normal_n_print(const char *format, va_list va, int i)
{
  char	*percent_expr;
  int	integer;
  int	len;
  int	c;

  if (!(percent_expr = malloc(sizeof (char) * my_strlen(format) + 1)))
    return (-1);
  my_strncpy(percent_expr, format, i + 2);
  len = my_strlen(my_strdup(int_to_char(my_getnbr(percent_expr))));
  integer = my_getnbr(percent_expr);
  c = percent_expr[len];
  if (c != 'd' && c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'D'
      && c != 'U' && c != 'O' && c != 's')
    {
      my_putstr_error("Invalid argument beside '%.' in my_printf function\n");
      return (84);
    }
  (c == 's') ? my_putstr(char_to_nchar(va, integer)) : c;
  (c == 'd' || c == 'u' || c == 'D'
   || c == 'i' || c == 'U') ? NBR(int_to_nint(va_arg(va, int), integer)) : c;
  (c == 'o') ? NNBR(va_arg(va, int), "01234567", integer) : c;
  (c == 'O') ? NNBR(va_arg(va, int), "01234567", integer) : c;
  (c == 'x') ? NNBR(va_arg(va, int), "0123456789abcdef", integer) : c;
  (c == 'X') ? NNBR(va_arg(va, int), "0123456789ABCDEF", integer) : c;
  return (0);
}

int     my_printf(const char *format, ...)
{
  va_list       va;
  int           i;

  va_start(va, format);
  i = 0;
  if (format == NULL)
    return (my_putstr(NULL));
  while (format[i] != '\0')
    {
      if (format[i] == '%' && format[i + 1] != '%' && format[i + 1] != '.')
	{
	  normal_print(format[i + 1], va);
	  i = i + 2;
	}
      else if (format[i] == '%' && format[i + 1] != '%'
	       && format[i + 1] == '.')
	{
	  normal_n_print(format, va, i);
	  i = i + nb_arg(format, i);
	}
      else
	my_putchar(format[i++]);
    }
  va_end(va);
  return (0);
}

