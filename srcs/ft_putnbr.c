/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:11:02 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/20 09:03:44 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int nb)
{
	long nb_tmp;

	nb_tmp = nb;
	if (nb_tmp < 0)
	{
		nb_tmp = nb_tmp * -1;
		ft_putchar('-');
	}
	if (nb_tmp < -9 || nb_tmp > 9)
		ft_putnbr((nb_tmp / 10));
	ft_putchar(nb_tmp % 10 + '0');
}
