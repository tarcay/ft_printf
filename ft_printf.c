/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:31:09 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 16:31:33 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int ft_printf(const char *str, ...)
{
    int i;
    int j;
    int k;
    char *flag;

    i = 0;
    j = 0;
    k = 0;
    va_list args;
    va_start(args, str);
    while(str[i])
    {
        while(str[i] == '%' && str[i])
        {
            flag = ft_parse_flag(&str[i]);
            j = j + ft_select_flag(flag, args);
            i = i + ft_strlen(flag);
            k = k + ft_strlen(flag);
            free(flag);
        }
        ft_putchar(str[i]);
        if (str[i] != '%' && str[i] != '\0')
            i++;
    }
    va_end(args);
    return ((i - k) + j);
}