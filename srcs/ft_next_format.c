/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:36:54 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/27 18:45:25 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_next_format(char *input, int index)
{
	while (ft_is_conv_char(input[index]) != 1)
	{
		if (!input[index] || ft_is_flag(input[index]) == 0)
			return (-1);
		index++;
	}
	return (index + 1);
}
