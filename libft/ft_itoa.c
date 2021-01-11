/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:44:47 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/31 11:38:45 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

static int	is_min_int(int nb)
{
	if (nb == -2147483648)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int		nb;
	int		index;
	int		min_int;
	char	*str;

	min_int = is_min_int(n) == 0 ? 0 : 1;
	nb = is_min_int(n) == 0 ? n : ++n;
	nb = nb < 0 ? -nb : nb;
	if (!(str = malloc(sizeof(char) * (int_len(nb) + (n < 0 ? 1 : 0) + 1))))
		return (NULL);
	index = n < 0 ? int_len(nb) + 1 : int_len(nb);
	str[index] = '\0';
	str[0] = n < 0 ? '-' : ' ';
	while (--index && nb >= 10)
	{
		str[index] = nb % 10 + '0';
		if (min_int == 1)
		{
			str[index] = str[index] + 1;
			min_int = 0;
		}
		nb = nb / 10;
	}
	str[index] = nb % 10 + '0';
	return (str);
}
