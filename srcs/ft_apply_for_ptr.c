/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:49:51 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/29 22:10:32 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_nb_ul(unsigned long nb)
{
	int size;

	size = 1;
	ft_base_ul(nb, &size, 0, 0);
	return (size + 2);
}

static void	ft_print_ptr(t_flags *elem, unsigned long arg)
{
	int	size;
	int size_tmp;

	size = 1;
	size_tmp = count_nb_ul(arg);
	ft_putstr("0x");
	if (arg == 0 && elem->dt == 1)
		return ;
	ft_base_ul(arg, &size, elem->dot - size_tmp + 2, 1);
}

int			ft_apply_for_ptr(t_flags *elem, va_list args)
{
	unsigned long	arg;

	if (elem->star == 1 || elem->star == 2)
		elem->width = va_arg(args, int);
	if (elem->star == 2 || elem->star == 3)
		elem->dot = va_arg(args, int);
	arg = (unsigned long)va_arg(args, void *);
	elem->arg_size = count_nb_ul(arg);
	elem->dt == 1 && arg == 0 ? elem->arg_size = 0 : 0;
	elem->dot > elem->arg_size ? elem->arg_size = elem->dot + 2 : 0;
	if ((elem->minius || elem->width < 0) && ++elem->minius)
	{
		elem->width < 0 ? elem->width *= -1 : 0;
		ft_print_ptr(elem, arg);
		ft_print_width(elem->width, elem->arg_size, 1);
	}
	if (!elem->minius)
	{
		if (elem->zero == 0)
			ft_print_width(elem->width, elem->arg_size, 1);
		if (elem->zero == 1)
			ft_print_width(elem->width, elem->arg_size, 0);
		ft_print_ptr(elem, arg);
	}
	return (elem->arg_size >= elem->width ? elem->arg_size : elem->width);
}
