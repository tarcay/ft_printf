#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int			ft_printf(const char *input, ...);
int			ft_print_addr(va_list arg);
char		*ft_parse_flag(const char *flag);
int			ft_select_flag(const char *flag, va_list arg);
int			ft_print_str(va_list arg);
int			ft_strcmp(char *s1, char *s2);
int			ft_print_unsigned(va_list arg);
void		ft_putnbr_u(unsigned int nb, int *size);
int			ft_print_int(va_list arg);
void		ft_putnbr(int nb, int *size);
int			ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_print_char(va_list arg);
void		ft_putnbr_base(long nbr, char *base, int *size);

#endif