/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:08:39 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/26 16:09:45 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	if (!(lst))
		return ;
	if (f)
	{
		while (tmp)
		{
			f(tmp->content);
			tmp = tmp->next;
		}
	}
	return ;
}
