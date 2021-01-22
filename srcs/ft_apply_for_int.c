/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:00:04 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/22 08:35:13 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	swt(int size_width, int arg_int, int arg_size, int dot, int index)
{
	long arg;

	arg = (long)arg_int;
	if (index == 0)
	{
		if (arg_size > 0)
			ft_putnbr(arg, dot - ft_count_size_nb(arg, 1));
		ft_print_width(size_width, arg_size, 1);
	}
	if (index == 1)
	{
		ft_print_width(size_width, arg_size, 1);
		if (arg_size > 0)
			ft_putnbr(arg, dot - ft_count_size_nb(arg, 1));
	}
	if (index == 2)
	{
		ft_print_width(size_width, arg_size, 0);
		if (arg_size > 0)
			ft_putnbr(arg, dot - ft_count_size_nb(arg, 1));
	}
}

int			ft_apply_for_int(t_flags *format, va_list args)
{
	int	arg_int;
	int	arg_size;

	if (format && args)
	{
		if (format->star > 0)
			format->width = va_arg(args, int);
		arg_int = va_arg(args, int);
		arg_size = ft_count_size_nb((long)arg_int, 0);
		if (format->dot > arg_size)
		{
			arg_size = format->dot;
			if (arg_int < 0)
				arg_size++;
		}
		format->dot == -1 && arg_int == 0 ? arg_size = 0 : 0;
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
