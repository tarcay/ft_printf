/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:17:33 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/25 16:36:28 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_width(int size_width, int size_arg, int index)
{
	int	counter;

	counter = 0;
	if (index == 0 && size_width > size_arg)
	{
		while (counter < (size_width - size_arg))
		{
			ft_putchar('0');
			counter++;
		}
	}
	else if (index == 1 && size_width > size_arg)
	{
		while (counter < (size_width - size_arg))
		{
			ft_putchar(' ');
			counter++;
		}
	}
}
