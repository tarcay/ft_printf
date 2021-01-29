/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:51:00 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/29 22:10:54 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	*ft_lst_new_elem(void)
{
	t_flags	*struct_flags;

	if (!(struct_flags = malloc(sizeof(t_flags))))
		return (NULL);
	struct_flags->arg = 0;
	struct_flags->arg_size = 0;
	struct_flags->type = 0;
	struct_flags->star = 0;
	struct_flags->minius = 0;
	struct_flags->dot = 0;
	struct_flags->zero = 0;
	struct_flags->width = 0;
	struct_flags->size_flag = 0;
	struct_flags->dt = 0;
	struct_flags->next = NULL;
	return (struct_flags);
}
