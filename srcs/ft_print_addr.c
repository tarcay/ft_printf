/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:18:14 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 16:26:19 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_addr(va_list arg)
{
	int size;

	size = 1;
	ft_putstr("0x");
	ft_putnbr_base((long)va_arg(arg, void *), "0123456789abcdef", &size);
	return (size + 2);
}