/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 13:10:12 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/31 11:34:29 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	char			*s_tmp;

	s_tmp = (char *)s;
	if (start >= ft_strlen(s_tmp) || len <= 0 || !s)
		return (ft_strdup(""));
	else
	{
		if (!(str = malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = 0;
		while (i < len && *s_tmp)
		{
			str[i] = s_tmp[start];
			i++;
			start++;
		}
		str[i] = '\0';
		return (str);
	}
}
