/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:17:16 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 16:26:26 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(va_list arg)
{
	int size;

	size = ft_putchar((char)va_arg(arg, int));
	return(size);
}