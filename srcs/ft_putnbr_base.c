/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:09:35 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/11 16:36:59 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_base(char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

static char	count_base(int index, char *base)
{
	int i;

	i = 0;
	while (i < index)
		i++;
	return (base[i]);
}

static int		base_is_valide(char *base)
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

void 	ft_putnbr_base(long nbr, char *base, int *size)
{
	if (base_is_valide(base) == 1)
	{
		if (nbr < 0)
		{
			nbr = nbr * -1;
			ft_putchar('-');
		}
		if (nbr >= check_base(base))
        {
			ft_putnbr_base((nbr / check_base(base)), base, size);
            *size = *size + 1;
		}
        ft_putchar(count_base(nbr % check_base(base), base));
    }
}