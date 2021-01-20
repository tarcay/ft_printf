/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:00:04 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/18 22:07:40 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_size_int(int nb)
{
	int	count;

	count = 1;
	if (nb < 0)
		count++;
	while (nb < -9 || nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static void	switch_print(int size_width, int arg_int, int arg_size, int index)
{
	if (index == 0)
	{
		ft_putnbr(arg_int);
		ft_print_width(size_width, arg_size, 1);
	}
	if (index == 1)
	{
		ft_print_width(size_width, arg_size, 1);
		ft_putnbr(arg_int);
	}
	if (index == 2)
	{
		ft_print_width(size_width, arg_size, 0);
		ft_putnbr(arg_int);
	}
}

int			ft_apply_for_int(t_flags *format, va_list args)
{
	int	arg_int;
	int	arg_size;

	arg_size = 0;
	if (format && args)
	{
		if (format->star > 0)
			format->width = va_arg(args, int);
		arg_int = va_arg(args, int);
		arg_size = count_size_int(arg_int);
		if (format->minius)
			switch_print(format->width, arg_int, arg_size, 0);
		if (!format->minius && format->zero == 0)
			switch_print(format->width, arg_int, arg_size, 1);
		if (!format->minius && format->zero == 1)
			switch_print(format->width, arg_int, arg_size, 2);
		return (arg_size >= format->width ? arg_size : format->width);
	}
	return (0);
}
