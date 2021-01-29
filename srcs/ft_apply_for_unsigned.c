/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:51:36 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/29 13:31:12 by tarcay           ###   ########.fr       */
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
			ft_putnbr((long)arg_conv, dot, 0);
		return (ft_count_size_nb((long)arg_conv, 0));
	}
	else
	{
		arg_conv = (unsigned int)arg;
		if (index == 1)
			ft_putnbr((long)arg_conv, dot, 0);
		return (ft_count_size_nb((long)arg_conv, 0));
	}
}

static void	swt(t_flags *elem, int arg_int, int index)
{
	int dot_size;

	dot_size = elem->dot - ft_print_and_count_unsigned(arg_int, 0, elem->dot);
	if (index == 0)
	{
		if (elem->arg_size > 0)
			ft_print_and_count_unsigned(arg_int, 1, dot_size);
		ft_print_width(elem->width, elem->arg_size, 1);
	}
	if (index == 1)
	{
		ft_print_width(elem->width, elem->arg_size, 1);
		if (elem->arg_size > 0)
			ft_print_and_count_unsigned(arg_int, 1, dot_size);
	}
	if (index == 2)
	{
		ft_print_width(elem->width, elem->arg_size, 0);
		if (elem->arg_size > 0)
			ft_print_and_count_unsigned(arg_int, 1, dot_size);
	}
}

int			ft_apply_for_unsigned(t_flags *elem, va_list args)
{
	int	arg;

	if (elem->star == 1 || elem->star == 2)
		elem->width = va_arg(args, int);
	if (elem->star == 2 || elem->star == 3)
		elem->dot = va_arg(args, int);
	arg = va_arg(args, int);
	elem->arg_size = ft_print_and_count_unsigned(arg, 0, 0);
	elem->dot > elem->arg_size ? elem->arg_size = elem->dot : 0;
	elem->dot_is_neg == 1 && arg == 0 ? elem->arg_size = 0 : 0;
	if ((elem->minius || elem->width < 0) && ++elem->minius)
	{
		elem->width < 0 ? elem->width *= -1 : 0;
		swt(elem, arg, 0);
	}
	if (!elem->minius && elem->zero == 0)
		swt(elem, arg, 1);
	if (!elem->minius && elem->zero == 1)
		swt(elem, arg, 2);
	return (elem->arg_size >= elem->width ? elem->arg_size : elem->width);
}
