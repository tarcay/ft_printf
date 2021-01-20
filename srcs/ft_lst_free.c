/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:53:02 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/20 08:59:43 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_lst_free(t_flags **lst)
{
	t_flags	*tmp;
	t_flags	*element;

	if (!(*lst))
		return ;
	element = *lst;
	while (element)
	{
		tmp = element->next;
		element = ft_lst_new_elem();
		free(element);
		element = tmp;
	}
	*lst = NULL;
}
