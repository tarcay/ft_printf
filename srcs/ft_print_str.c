/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:16:12 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 16:26:37 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_str(va_list arg)
{
	char *arg_tmp;

	arg_tmp = va_arg(arg, char *);
	ft_putstr(arg_tmp);
	return (ft_strlen(arg_tmp));
}