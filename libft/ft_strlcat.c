/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:17:45 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/31 11:16:37 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0' && i < n)
		i++;
	j = i;
	while (src[i - j] != '\0' && i < n - 1 && n > 0)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < n)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
