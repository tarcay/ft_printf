/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:31:09 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/27 18:47:42 by tarcay           ###   ########.fr       */
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
		counter = counter + format_tmp->size_flag;
		format_tmp = format_tmp->next;
	}
	return (counter);
}

static int	size_output(t_flags *format, const char *str)
{
	return (ft_strlen(str) - size_format(format));
}

static void	display(t_flags *lst, va_list args, char *str, int *size_arg)
{
	t_flags	*lst_tmp;
	int		index;

	lst_tmp = lst;
	index = 0;
	while (str[index])
	{
		if (str[index] == '%' && ft_next_format(str, index + 1) != -1)
		{
			analyze_type(lst_tmp, args, size_arg);
			index += lst_tmp->size_flag;
			lst_tmp = lst_tmp->next;
			if (!str[index])
				break ;
		}
		if (str[index] != '%' ||
			(str[index] == '%' && ft_next_format(str, index + 1) == -1))
		{
			ft_putchar(str[index]);
			index++;
		}
	}
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	*lst;
	int		size_args;
	int		size_str;

	if (!str || (*str == '%' && ft_strlen(str) == 1))
		return (-1);
	ft_create_lst_format(&lst, (char *)str);
	size_args = 0;
	size_str = size_output(lst, str);
	va_start(args, str);
	display(lst, args, (char *)str, &size_args);
	va_end(args);
	ft_lst_free(&lst);
	return (size_str + size_args);
}
