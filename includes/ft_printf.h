/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:03:17 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/23 08:49:08 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONV_CHAR "cspdiuxX%"
# define FLAGS "*-.0123456789"

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_flags
{
	char			type;
	int				star;
	int				minius;
	int				dot;
	int				zero;
	int				width;
	int				size;
	struct s_flags	*next;
}				t_flags;

int				ft_printf(const char *input, ...);
int				ft_apply_for_str(t_flags *format, va_list args);
int				ft_apply_for_char(t_flags *format, va_list args);
int				ft_apply_for_int(t_flags *format, va_list args);
int				ft_apply_for_ptr(t_flags *format, va_list args);
int				ft_apply_for_unsigned(t_flags *format, va_list args);
int				ft_apply_for_hexa(t_flags *format, va_list args, int index);
int				ft_apply_for_percent(void);
int				ft_is_conv_char(char c);
int				ft_is_flag(char c);
int				ft_putchar(char c);
int				ft_count_size_nb(long nb, int dot_size);
void			ft_print_precision(int arg_size, int dot);
void			ft_putnbr(long nb, int dot);
void			ft_putstr(char *str);
void			ft_ui(unsigned int nbr, char *base, int *size, int dot, int index);
void			ft_ul(unsigned long nbr, char *base, int *size, int dot, int index);
void			ft_create_lst_format(t_flags **lst_format, char *input);
void			ft_lst_free(t_flags **lst);
void			ft_print_width(int size_width, int size_arg, int index);
t_flags			*ft_lst_new_elem(void);

#endif
