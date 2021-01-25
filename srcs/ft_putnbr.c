/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:11:02 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/25 18:57:51 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(long nb, int dot, int zero)
{
	if (nb < 0)
	{
		nb = nb * -1;
		if (zero == 0)
			ft_putchar('-');
	}
	while (dot > 0)
	{
		ft_putchar('0');
		dot--;
	}
	if (nb < -9 || nb > 9)
		ft_putnbr((nb / 10), dot, zero);
	ft_putchar(nb % 10 + '0');
}
