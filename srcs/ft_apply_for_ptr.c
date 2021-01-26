/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:49:51 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/26 10:05:54 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_and_count_addr(unsigned long arg, int index)
{
	int	size;

	size = 1;
	if (!arg)
	{
		if (index == 1)
			ft_putstr("(nil)");
		return (5);
	}
	if (index == 1)
		ft_putstr("0x");
	ft_base_ul(arg, &size, 0, index);
	return (size + 2);
}

int			ft_apply_for_ptr(t_flags *elem, va_list args)
{
	long	arg;

	if (elem->star > 0)
		elem->width = va_arg(args, int);
	arg = (unsigned long)va_arg(args, void *);
	elem->arg_size = ft_print_and_count_addr(arg, 0);
	if ((elem->minius || elem->width < 0) && ++elem->minius)
	{
		if (elem->width < 0)
			elem->width *= -1;
		ft_print_and_count_addr(arg, 1);
		ft_print_width(elem->width, elem->arg_size, 1);
	}
	if (!elem->minius)
	{
		ft_print_width(elem->width, elem->arg_size, 1);
		ft_print_and_count_addr(arg, 1);
	}
	return (elem->arg_size >= elem->width ? elem->arg_size : elem->width);
}
