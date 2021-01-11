/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:12:25 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/31 11:31:14 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*s_tmp;
	int		i;

	s_tmp = (char *)s;
	if (!(str = malloc(sizeof(char) * ft_strlen(s_tmp) + 1)))
		return (NULL);
	i = 0;
	while (s_tmp[i])
	{
		str[i] = s_tmp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
