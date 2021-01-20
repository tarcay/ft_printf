/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:49:51 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/20 18:29:09 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_and_count_addr(long arg, int index)
{
	int	size;

	size = 1;
	if (index == 1)
		ft_putstr("0x");
	if (arg)
		ft_putnbr_base(arg, "0123456789abcdef", &size, index);
	return (size + 2);
}

int			ft_apply_for_ptr(t_flags *format, va_list args)
{
	long	arg_long;
	int		arg_size;

	arg_size = 0;
	if (format && args)
	{
		if (format->star > 0)
			format->width = va_arg(args, int);
		arg_long = (long)va_arg(args, void *);
		arg_size = ft_print_and_count_addr(arg_long, 0);
		if (format->minius)
		{
			ft_print_and_count_addr(arg_long, 1);
			ft_print_width(format->width, arg_size, 1);
		}
		if (!format->minius)
		{
			ft_print_width(format->width, arg_size, 1);
			ft_print_and_count_addr(arg_long, 1);
		}
		return (arg_size >= format->width ? arg_size : format->width);
	}
	return (0);
}
