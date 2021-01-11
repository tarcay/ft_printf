/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:31:35 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/20 12:55:45 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	if (c == 0)
		return ((char *)s + i);
	i--;
	while (i >= 0)
	{
		if (str[i] + '\0' == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
