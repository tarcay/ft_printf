/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:13:26 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/18 11:15:59 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_apply_for_char(t_flags *format, va_list args)
{
	char	arg_char;

	if (format && args)
	{
		if (format->star > 0)
			format->width = va_arg(args, int);
		arg_char = (char)va_arg(args, char *);
		if (format->minius)
		{
			ft_putchar(arg_char);
			ft_print_width(format->width, 1, 1);
		}
		if (!format->minius)
		{
			ft_print_width(format->width, 1, 1);
			ft_putchar(arg_char);
		}
		return (format->width > 1 ? format->width : 1);
	}
	return (0);
}
