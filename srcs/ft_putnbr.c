/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:11:02 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/21 12:03:09 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(long nb, int precision)
{
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
    while(precision > 0)
	{
		ft_putchar('0');
		precision--;
	}
	if (nb < -9 || nb > 9)
		ft_putnbr((nb / 10), precision);
	ft_putchar(nb % 10 + '0');
}
