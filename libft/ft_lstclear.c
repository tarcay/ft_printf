/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:10:58 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/26 16:12:02 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*element;

	if (!(*lst))
		return ;
	if (del)
	{
		element = *lst;
		while (element)
		{
			tmp = element->next;
			del(element->content);
			free(element);
			element = tmp;
		}
		*lst = NULL;
	}
	else
		return ;
}
