/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:13:26 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/25 13:50:27 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_apply_for_char(t_flags *elem, va_list args)
{
	char	arg_char;

	if (elem && args)
	{
		if (elem->star > 0)
			elem->width = va_arg(args, int);
		arg_char = (char)va_arg(args, char *);
		if ((elem->minius || elem->width < 0) && ++elem->minius)
		{
			if (elem->width < 0)
				elem->width *= -1;
			ft_putchar(arg_char);
			ft_print_width(elem->width, 1, 1);
		}
		if (!elem->minius)
		{
			ft_print_width(elem->width, 1, 1);
			ft_putchar(arg_char);
		}
		return (elem->width > 1 ? elem->width : 1);
	}
	return (0);
}
