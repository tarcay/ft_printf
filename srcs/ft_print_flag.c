/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:21:32 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 21:33:36 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/globals.h"

char		*ft_parse_flag(const char *flag)
{
	int index;
	char *flag_cpy;

	if (!(flag_cpy = malloc(sizeof(char) * 5)))
		return (NULL);
	index = 0;
	flag_cpy[index] = flag[index];
	while ((flag_cpy[index] == (char)GLOBAL_d[index] ||
		    flag_cpy[index] == (char)GLOBAL_s[index] ||
		    flag_cpy[index] == (char)GLOBAL_c[index] ||
		    flag_cpy[index] == (char)GLOBAL_p[index] ||
		    flag_cpy[index] == (char)GLOBAL_i[index] ||
		    flag_cpy[index] == (char)GLOBAL_u[index] ||
		    flag_cpy[index] == (char)GLOBAL_x[index] ||
		    flag_cpy[index] == (char)GLOBAL_X[index]) &&
		    flag[index] != '\0')
	{
		index++;
		flag_cpy[index] = flag[index];
	};
	flag_cpy[index] = '\0';
	return (flag_cpy);
}

int		ft_select_flag(const char *flag, va_list arg)
{
	if (ft_strcmp((char *)flag, (char *)GLOBAL_d) == 0)
		return (ft_print_int(arg));
	else if (ft_strcmp((char *)flag, (char *)GLOBAL_s) == 0)
		return (ft_print_str(arg));
	else if (ft_strcmp((char *)flag, (char *)GLOBAL_c) == 0)
		return(ft_print_char(arg));
	else if (ft_strcmp((char *)flag, (char *)GLOBAL_p) == 0)
		return(ft_print_addr(arg));
	else if (ft_strcmp((char *)flag, (char *)GLOBAL_i) == 0)
		return(ft_print_int(arg));
	else if (ft_strcmp((char *)flag, (char *)GLOBAL_u) == 0)
		return(ft_print_unsigned(arg));
	else if (ft_strcmp((char *)flag, (char *)GLOBAL_x) == 0)
		return (0);
	else if (ft_strcmp((char *)flag, (char *)GLOBAL_X) == 0)
		return (0);
	else
		return (0);
}