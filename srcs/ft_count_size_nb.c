/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_size_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:19:48 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/21 17:34:49 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_count_size_nb(long nb, int dot_size)
{
	int	count;

	count = 1;
	if (nb < 0 && dot_size == 0)
		count++;
	while (nb < -9 || nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}