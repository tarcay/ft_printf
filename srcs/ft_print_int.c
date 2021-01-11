/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:14:43 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 16:26:31 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_int(va_list arg)
{
	int arg_tmp;
	int size;

	size = 1;
	arg_tmp = va_arg(arg, int);
	ft_putnbr(arg_tmp, &size);
	return (size);
}