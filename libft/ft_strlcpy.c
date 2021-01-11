/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:20:06 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/20 12:21:45 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*src_tmp;
	int		count;
	size_t	i;

	src_tmp = (char *)src;
	count = ft_strlen(src_tmp);
	if (size == 0)
		return (count);
	i = 0;
	while (src_tmp[i] != '\0' && i < (size - 1))
	{
		dest[i] = src_tmp[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}
