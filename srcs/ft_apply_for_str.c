/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_for_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:22:27 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/23 11:28:16 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_print_and_count_str(char *str, int index, int size_arg, int dot)
{
	if (str == NULL && dot != -1)
	{
		if (index == 1)
			ft_putstr("(null)");
		return (6);
	}
	if (str == NULL && dot == -1)
		return (0);
	if (index == 0)
		return (ft_strlen(str));
	if (index == 1)
	{
		while (*str && size_arg)
		{
			ft_putchar(*str);
			str++;
			size_arg--;
		}
	}
	return (!size_arg ? ft_strlen(str) : size_arg);
}

int				ft_apply_for_str(t_flags *format, va_list args)
{
	char	*arg_str;
	int		arg_size;

	if (format && args)
	{
		if (format->star > 0)
			format->width = va_arg(args, int);
		if (format->star > 1)
			format->dot = va_arg(args, int);
		arg_str = va_arg(args, char *);
		arg_size = ft_print_and_count_str(arg_str, 0, 0, format->dot);
		if (format->dot == -1)
			arg_size = 0;
		if (format->dot > 0 && format->dot < arg_size)
			arg_size = format->dot;
		if ((format->minius || format->width < 0) && ++format->minius)
		{
			if (format->width < 0)
				format->width *= -1;
			ft_print_and_count_str(arg_str, 1, arg_size, format->dot);
			ft_print_width(format->width, arg_size, 1);
		}
		if (!format->minius)
		{
			ft_print_width(format->width, arg_size, 1);
			ft_print_and_count_str(arg_str, 1, arg_size, format->dot);
		}
		return (arg_size >= format->width ? arg_size : format->width);
	}
	return (0);
}
