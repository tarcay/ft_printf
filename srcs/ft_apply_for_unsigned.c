/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:51:36 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/21 17:41:26 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_and_count_unsigned(int arg, int index, int dot)
{
	int				size;
	unsigned int	arg_conv;

	arg_conv = 0;
	size = 1;
	if (arg < 0)
	{
		arg_conv = 4294967296 + arg;
		if (index == 1)
			ft_putnbr((long)arg_conv, dot);
		return (ft_count_size_nb((long)arg_conv, 0));
	}
	else
	{
		arg_conv = (unsigned int)arg;
		if (index == 1)
			ft_putnbr((long)arg_conv, dot);
		return (ft_count_size_nb((long)arg_conv, 0));
	}
}

static void	swt(int size_width, int arg_int, int arg_size, int dot, int index)
{
	int dot_size;

	dot_size = dot - ft_print_and_count_unsigned(arg_int, 0, dot);
	if (index == 0)
	{
		if (arg_size > 0)
			ft_print_and_count_unsigned(arg_int, 1, dot_size);
		ft_print_width(size_width, arg_size, 1);
	}
	if (index == 1)
	{
		ft_print_width(size_width, arg_size, 1);
		if (arg_size > 0)
			ft_print_and_count_unsigned(arg_int, 1, dot_size);
	}
	if (index == 2)
	{
		ft_print_width(size_width, arg_size, 0);
		if (arg_size > 0)
			ft_print_and_count_unsigned(arg_int, 1, dot_size);
	}
}

int			ft_apply_for_unsigned(t_flags *format, va_list args)
{
	int	arg_int;
	int	arg_size;

	arg_size = 0;
	if (format && args)
	{
		if (format->star > 0)
			format->width = va_arg(args, int);
		arg_int = va_arg(args, int);
		arg_size = ft_print_and_count_unsigned(arg_int, 0, 0);
		if (format->dot > arg_size)
			arg_size = format->dot;
		format->dot == -1 ? arg_size = 0 : 0;
		if (format->minius)
			swt(format->width, arg_int, arg_size, format->dot, 0);
		if (!format->minius && format->zero == 0)
			swt(format->width, arg_int, arg_size, format->dot, 1);
		if (!format->minius && format->zero == 1)
			swt(format->width, arg_int, arg_size, format->dot, 2);
		return (arg_size >= format->width ? arg_size : format->width);
	}
	return (0);
}
