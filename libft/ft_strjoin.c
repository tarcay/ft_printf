/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:14:50 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/20 12:17:31 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 && s2)
	{
		if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		i = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
