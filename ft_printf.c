/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:31:09 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/20 15:18:18 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	analyze_type(t_flags *format, va_list args, int *size)
{
	if (format->type == 'd')
		*size = *size + ft_apply_for_int(format, args);
	if (format->type == 'i')
		*size = *size + ft_apply_for_int(format, args);
	if (format->type == 's')
		*size = *size + ft_apply_for_str(format, args);
	if (format->type == 'c')
		*size = *size + ft_apply_for_char(format, args);
	if (format->type == 'p')
		*size = *size + ft_apply_for_ptr(format, args);
	if (format->type == 'u')
		*size = *size + ft_apply_for_unsigned(format, args);
	if (format->type == 'x')
		*size = *size + ft_apply_for_hexa(format, args, 1);
	if (format->type == 'X')
		*size = *size + ft_apply_for_hexa(format, args, 2);
	if (format->type == '%')
		*size = *size + ft_apply_for_percent();
	return ;
}

static int	size_format(t_flags *format_lst)
{
	t_flags	*format_tmp;
	int		counter;

	format_tmp = format_lst;
	counter = 0;
	while (format_tmp)
	{
		counter = counter + format_tmp->size;
		format_tmp = format_tmp->next;
	}
	return (counter);
}

static int	size_output(t_flags *format, const char *str)
{
	return (ft_strlen(str) - size_format(format));
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	*format_lst;
	t_flags	*format_lst_tmp;
	int		size_arg;
	int		size_str;

	ft_create_lst_format(&format_lst, (char *)str);
	size_arg = 0;
	size_str = size_output(format_lst, str);
	format_lst_tmp = format_lst;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			analyze_type(format_lst_tmp, args, &size_arg);
			str += (format_lst_tmp->size);
			format_lst_tmp = format_lst_tmp->next;
			if (!*str)
				break ;
		}
		ft_putchar(*str);
		str++;
	}
	va_end(args);
	ft_lst_free(&format_lst);
	return (size_str + size_arg);
}
