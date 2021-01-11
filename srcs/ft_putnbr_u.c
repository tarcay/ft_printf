/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:12:32 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 16:27:03 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_u(unsigned int nb, int *size)
{
	long nb_tmp;

	nb_tmp = nb;
	if (nb > 9)
	{
		ft_putnbr_u((nb_tmp / 10), size);
		*size = *size + 1;
	}
	ft_putchar(nb_tmp % 10 + '0');
}