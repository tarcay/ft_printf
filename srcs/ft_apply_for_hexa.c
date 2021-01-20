/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:08:05 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/19 18:13:08 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_and_count_hexa(int arg, int index)
{
	int	size;

	size = 1;
	if (index == 0)
		ft_putnbr_base(arg, "0123456789abcdef", &size, 0);
	if (index == 1)
		ft_putnbr_base(arg, "0123456789abcdef", &size, 1);
	if (index == 2)
		ft_putnbr_base(arg, "0123456789ABCDEF", &size, 1);
	return (size);
}

int			ft_apply_for_hexa(t_flags *format, va_list args, int index)
{
	int	arg_int;
	int	arg_size;

	arg_size = 0;
	if (format && args)
	{
		if (format->star > 0)
			format->width = va_arg(args, int);
		arg_int = va_arg(args, int);
		arg_size = ft_print_and_count_hexa(arg_int, 0);
		if (format->minius)
		{
			ft_print_and_count_hexa(arg_int, index);
			ft_print_width(format->width, arg_size, 1);
		}
		if (!format->minius)
		{
			ft_print_width(format->width, arg_size, 1);
			ft_print_and_count_hexa(arg_int, index);
		}
		return (arg_size >= format->width ? arg_size : format->width);
	}
	return (0);
}
