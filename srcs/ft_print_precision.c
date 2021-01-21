/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:23:22 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/21 11:24:01 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_print_precision(int arg_size, int dot)
{
	if (dot > arg_size)
	{
		dot = dot - arg_size;
		while (dot)
		{
			ft_putchar('0');
			dot--;
		}
	}
}