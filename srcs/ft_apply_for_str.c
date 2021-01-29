/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:22:27 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/29 16:12:38 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_print_and_count_str(t_flags *elem, char *str, int index)
{
	int arg_size;

	arg_size = elem->arg_size;
	if (index == 0)
		return (ft_strlen(str));
	if (index == 1)
	{
		while (*str && arg_size)
		{
			ft_putchar(*str);
			str++;
			arg_size--;
		}
	}
	return (!arg_size ? ft_strlen(str) : arg_size);
}

int				ft_apply_for_str(t_flags *elem, va_list args)
{
	char	*arg;

	if (elem->star == 1 || elem->star == 2)
		elem->width = va_arg(args, int);
	if (elem->star == 2 || elem->star == 3)
		elem->dot = va_arg(args, int);
	(elem->star == 2 || elem->star == 3) && elem->dot == 0 ? elem->dot_is_neg = 1 : 0;
	arg = va_arg(args, char *);
	arg == NULL ? arg = NL : 0;
	elem->arg_size = ft_print_and_count_str(elem, arg, 0);
	elem->dot_is_neg == 1 ? elem->arg_size = 0 : 0;
	if (elem->dot > 0 && elem->dot < elem->arg_size)
		elem->arg_size = elem->dot;
	if ((elem->minius || elem->width < 0) && ++elem->minius)
	{
		elem->width < 0 ? elem->width *= -1 : 0;
		ft_print_and_count_str(elem, arg, 1);
		ft_print_width(elem->width, elem->arg_size, 1);
	}
	if (!elem->minius)
	{
		ft_print_width(elem->width, elem->arg_size, 1);
		ft_print_and_count_str(elem, arg, 1);
	}
	return (elem->arg_size >= elem->width ? elem->arg_size : elem->width);
}
