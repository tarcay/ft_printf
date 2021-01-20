/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:51:36 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/19 11:04:25 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr_u(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr_u(nb / 10);
	ft_putchar(nb % 10 + '0');
}

static int	count_size_unsigned(unsigned int nb)
{
	int	count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static int	ft_print_and_count_unsigned(int arg, int index)
{
	int				size;
	unsigned int	arg_conv;

	arg_conv = 0;
	size = 1;
	if (arg < 0)
	{
		arg_conv = 4294967296 + arg;
		if (index == 1)
			ft_putnbr_u(arg_conv);
		return (count_size_unsigned(arg_conv));
	}
	else
	{
		arg_conv = (unsigned int)arg;
		if (index == 1)
			ft_putnbr_u(arg_conv);
		return (count_size_unsigned(arg_conv));
	}
}

static void	switch_print(int size_width, int arg_int, int arg_size, int index)
{
	if (index == 0)
	{
		ft_print_and_count_unsigned(arg_int, 1);
		ft_print_width(size_width, arg_size, 1);
	}
	if (index == 1)
	{
		ft_print_width(size_width, arg_size, 1);
		ft_print_and_count_unsigned(arg_int, 1);
	}
	if (index == 2)
	{
		ft_print_width(size_width, arg_size, 0);
		ft_print_and_count_unsigned(arg_int, 1);
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
		arg_size = ft_print_and_count_unsigned(arg_int, 0);
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
