/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 11:45:11 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/20 11:50:52 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_tmp;
	char	*src_tmp;
	size_t	i;

	if (dest == src)
		return (dest);
	dest_tmp = (char *)dest;
	src_tmp = (char *)src;
	if (src < dest)
	{
		while (n--)
			dest_tmp[n] = src_tmp[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dest);
}
