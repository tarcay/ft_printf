/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:41:53 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/31 11:38:43 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	end = ft_strlen(s1);
	start = 0;
	while (is_set(s1[start], set) == 1 && s1[start])
		start++;
	if (start > --end)
		return (ft_strdup(""));
	while (is_set(s1[end], set) == 1 && end >= 0)
		end--;
	if (!(str = malloc(sizeof(char) * (end - start) + 2)))
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
