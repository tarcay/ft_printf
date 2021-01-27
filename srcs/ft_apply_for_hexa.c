/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:08:05 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/27 09:37:33 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_nb_hexa(int nb)
{
	int size;

	size = 1;
	ft_base_ui(nb, &size, 0, 0);
	return (size);
}

static int	ft_print_hexa(int arg, int dot, int index)
{
	int	size;
	int size_tmp;

	size = 1;
	size_tmp = count_nb_hexa(arg);
	if (arg == 0 && dot == -1)
		return (0);
	if (index == 1)
		ft_base_ui(arg, &size, dot - size_tmp, index);
	if (index == 2)
		ft_base_ui(arg, &size, dot - size_tmp, index);
	return (size);
}

int			ft_apply_for_hexa(t_flags *elem, va_list args, int index)
{
	int	arg;

	if (elem->star == 1 || elem->star == 2)
		elem->width = va_arg(args, int);
	if (elem->star == 2 || elem->star == 3)
		elem->dot = va_arg(args, int);
	arg = va_arg(args, int);
	elem->arg_size = count_nb_hexa(arg);
	elem->dot == -1 && arg == 0 ? elem->arg_size = 0 : 0;
	elem->dot > elem->arg_size ? elem->arg_size = elem->dot : 0;
	if ((elem->minius || elem->width < 0) && ++elem->minius)
	{
		elem->width < 0 ? elem->width *= -1 : 0;
		ft_print_hexa(arg, elem->dot, index);
		ft_print_width(elem->width, elem->arg_size, 1);
	}
	if (!elem->minius)
	{
		if (elem->zero == 0)
			ft_print_width(elem->width, elem->arg_size, 1);
		if (elem->zero == 1)
			ft_print_width(elem->width, elem->arg_size, 0);
		ft_print_hexa(arg, elem->dot, index);
	}
	return (elem->arg_size >= elem->width ? elem->arg_size : elem->width);
}
