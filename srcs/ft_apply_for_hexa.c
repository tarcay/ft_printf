/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:08:05 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/23 09:57:44 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_nb_hexa(int nb)
{
	int size;

	size = 1;
	ft_ui(nb, "0123456789abcdef", &size, 0, 0);
	return (size);
}

static int	ft_print_and_count_hexa(int arg, int dot, int index)
{
	int	size;
	int size_arg;

	size = 1;
	size_arg = count_nb_hexa(arg);
	if (index == 1)
		ft_ui(arg, "0123456789abcdef", &size, dot - size_arg, 1);
	if (index == 2)
		ft_ui(arg, "0123456789ABCDEF", &size, dot - size_arg, 1);
	return (size);
}

int			ft_apply_for_hexa(t_flags *format, va_list args, int index)
{
	int	arg_int;
	int	arg_size;

	if (format && args)
	{
		if (format->star > 0)
			format->width = va_arg(args, int);
		arg_int = va_arg(args, int);
		arg_size = count_nb_hexa(arg_int);
		if (format->dot > arg_size)
			arg_size = format->dot;
		if ((format->minius || format->width < 0) && ++format->minius)
		{
			if (format->width < 0)
				format->width *= -1;
			ft_print_and_count_hexa(arg_int, format->dot, index);
			ft_print_width(format->width, arg_size, 1);
		}
		if (!format->minius && format->zero == 0)
		{
			ft_print_width(format->width, arg_size, 1);
			ft_print_and_count_hexa(arg_int, format->dot, index);
		}
		if (!format->minius && format->zero == 1)
		{
			ft_print_width(format->width, arg_size, 0);
			ft_print_and_count_hexa(arg_int, format->dot, index);
		}
		return (arg_size >= format->width ? arg_size : format->width);
	}
	return (0);
}
