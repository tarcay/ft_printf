/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 01:40:15 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/20 09:56:03 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int		i;
	int		negativ;
	int		result;
	char	*str;

	negativ = 0;
	i = 0;
	str = (char *)nptr;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negativ++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (negativ == 1 ? -result : result);
}
