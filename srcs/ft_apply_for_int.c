/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:00:04 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/25 14:08:17 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	swt(t_flags *elem, int arg, int index)
{
	long arg_tmp;

	arg_tmp = (long)arg;
	if (arg < 0 && elem->dot > ft_count_size_nb(arg, 1))
		elem->arg_size = elem->dot + 1;
	if (index == 0)
	{
		if (elem->arg_size > 0)
			ft_putnbr(arg, elem->dot - ft_count_size_nb(arg, 1));
		ft_print_width(elem->width, elem->arg_size, 1);
	}
	if (index == 1)
	{
		ft_print_width(elem->width, elem->arg_size, 1);
		if (elem->arg_size > 0)
			ft_putnbr(arg, elem->dot - ft_count_size_nb(arg, 1));
	}
	if (index == 2)
	{
		ft_print_width(elem->width, elem->arg_size, 0);
		if (elem->arg_size > 0)
			ft_putnbr(arg, elem->dot - ft_count_size_nb(arg, 1));
	}
}

int			ft_apply_for_int(t_flags *elem, va_list args)
{
	int	arg;

	if (elem->star > 0)
		elem->width = va_arg(args, int);
	if (elem->star > 1)
		elem->dot = va_arg(args, int);
	arg = va_arg(args, int);
	elem->arg_size = ft_count_size_nb((long)arg, 0);
	if (elem->dot > elem->arg_size)
	{
		elem->arg_size = elem->dot;
		arg < 0 ? elem->arg_size++ : 0;
	}
	elem->dot == -1 && arg == 0 ? elem->arg_size = 0 : 0;
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
