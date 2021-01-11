/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:11:49 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/20 10:15:05 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	total;
	size_t	i;

	total = nmemb * size;
	if (!(str = malloc(total)))
		return (NULL);
	i = 0;
	while (total--)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
