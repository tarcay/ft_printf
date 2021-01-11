/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:25:08 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/31 11:38:47 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (f)(unsigned int, char))
{
	int		index;
	char	*str;

	if (s && f)
	{
		if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		index = 0;
		while (s[index])
		{
			str[index] = f(index, s[index]);
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
