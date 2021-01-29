/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_ul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:09:35 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/29 16:52:54 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	check_base(char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

static char			count_base(int index, char *base)
{
	int i;

	i = 0;
	while (i < index)
		i++;
	return (base[i]);
}

static int			base_is_valide(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (check_base(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

// void				ft_base_ul(unsigned long nbr, int *size, int dot, int index)
// {
// 	char	*base;

// 	index == 0 || index == 1 ? base = BASE_1 : 0;
// 	index == 2 ? base = BASE_2 : 0;
// 	if (base_is_valide(base) == 1)
// 	{
// 		if (nbr < 0)
// 		{
// 			nbr = nbr * -1;
// 			ft_putchar('-');
// 		}
// 		while (dot > 0)
// 		{
// 			if (index == 1)
// 				ft_putchar('0');
// 			dot--;
// 			*size = *size + 1;
// 		}
// 		if (nbr >= check_base(base))
// 		{
// 			ft_base_ul((nbr / check_base(base)), size, dot, index);
// 			*size = *size + 1;
// 		}
// 		index == 1 ? ft_putchar(count_base(nbr % check_base(base), base)) : 0;
// 	}
// }

void				ft_base_ul(unsigned long nbr, int *size, int dot, int index)
{
	char	*base;

	base = BASE_1;
	if (base_is_valide(base) == 1)
	{
		if (nbr < 0)
		{
			nbr = nbr * -1;
			ft_putchar('-');
		}
		while (dot > 0)
		{
			ft_putchar('0');
			dot--;
		}
		if (nbr >= check_base(base))
		{
			ft_base_ui((nbr / check_base(base)), size, dot, index);
			*size = *size + 1;
		}
		if (index == 1)
			ft_putchar(count_base(nbr % check_base(base), base));
	}
}
