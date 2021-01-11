/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:19:22 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 16:26:44 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_unsigned(va_list arg)
{	
	int tmp;
	int size;
	unsigned int test;

	tmp = va_arg(arg, int);
	test = 0;
	size = 1;
	if (tmp < 0)
	{
		test = 4294967296 + tmp;
		ft_putnbr_u(test, &size);
		return (size);
	}
	else
	{
		test = (unsigned int)tmp;
		ft_putnbr_u(test, &size);
		return (size);
	}
}