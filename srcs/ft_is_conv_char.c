/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conv_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:43:35 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/20 09:04:42 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_is_conv_char(char c)
{
	char	*str;

	str = CONV_CHAR;
	if (c)
	{
		while (*str)
		{
			if (*str == c)
				return (1);
			str++;
		}
	}
	return (0);
}
