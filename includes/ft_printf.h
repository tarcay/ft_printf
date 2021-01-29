/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:03:17 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/29 22:08:01 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONV_CHAR "cspdiuxX%"
# define FLAGS "*-.0123456789"
# define BASE_1 "0123456789abcdef"
# define BASE_2 "0123456789ABCDEF"
# define NL "(null)"

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	long			arg;
	char			type;
	int				arg_size;
	int				star;
	int				minius;
	int				dot;
	int				zero;
	int				width;
	int				size_flag;
	int				dt;
	struct s_flags	*next;
}				t_flags;

int				ft_printf(const char *input, ...);
int				ft_apply_for_str(t_flags *format, va_list args);
int				ft_apply_for_char(t_flags *format, va_list args);
int				ft_apply_for_int(t_flags *format, va_list args);
int				ft_apply_for_ptr(t_flags *elem, va_list args);
int				ft_apply_for_unsigned(t_flags *format, va_list args);
int				ft_apply_for_hexa(t_flags *format, va_list args, int index);
int				ft_apply_for_percent(void);
int				ft_is_conv_char(char c);
int				ft_is_flag(char c);
int				ft_putchar(char c);
int				ft_count_size_nb(long nb, int dot_size);
int				ft_next_format(char *input, int index);
void			ft_putnbr(long nb, int dot, int zero);
void			ft_putstr(char *str);
void			ft_base_ui(unsigned int nbr, int *size, int dot, int index);
void			ft_base_ul(unsigned long nbr, int *size, int dot, int index);
void			ft_create_lst_format(t_flags **lst_format, char *input);
void			ft_lst_free(t_flags **lst);
void			ft_print_width(int size_width, int size_arg, int index);
t_flags			*ft_lst_new_elem(void);

#endif
