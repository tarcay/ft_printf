/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:54:13 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/22 09:49:45 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		next_format_in_input(char *input, int index)
{
	while (ft_is_conv_char(input[index]) != 1)
	{
		if(!input[index])
			return (-1);
		index++;
	}
	return (index + 1);
}

static void		ft_lstadd_end(t_flags **alst, t_flags *new)
{
	t_flags	*tmp;

	tmp = *alst;
	if (!(new))
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static t_flags	*ft_lst_init_elem(char *c, t_flags *format)
{
	if (c && format && (ft_is_flag(*c) == 1 || ft_is_conv_char(*c) == 1))
	{
		if (*c == '-')
		{
			format->minius = 1;
			format->zero = 0;
		}
		else if (*c >= '1' && *c <= '9' && format->width == 0 &&
				format->dot == 0)
			format->width = ft_atoi((char *)c);
		else if (ft_is_conv_char(*c))
			format->type = *c;
		else if (*c == '0' && format->minius == 0 && format->width == 0)
			format->zero = 1;
		else if (*c == '*')
			format->star = 1;
		if (*c == '.')
		{
			format->zero = 0;
			format->dot = ft_atoi((char *)c + 1);
			if (format->dot == 0)
				format->dot = -1;
		}
		return (format);
	}
	return (NULL);
}

static t_flags	*ft_lst_create_elem(char *format)
{
	t_flags	*element;
	char	*format_tmp;
	int		size;

	size = 1;
	if (format)
	{
		if (!(element = ft_lst_new_elem()))
			return (NULL);
		format_tmp = format;
		while (*format_tmp && ++size)
		{
			if (ft_is_conv_char(*format_tmp) == 1)
			{
				element = ft_lst_init_elem(format_tmp, element);
				element->size = size;
				break ;
			}
			if (!(element = ft_lst_init_elem(format_tmp, element)))
				return (NULL);
			format_tmp++;
		}
		return (element);
	}
	return (NULL);
}

void			ft_create_lst_format(t_flags **lst_format, char *input)
{
	int	i;

	i = 0;
	if (input)
	{
		*lst_format = NULL;
		while (input[i] && i != -1)
		{
			if (input[i] == '%')
			{
				ft_lstadd_end(lst_format, ft_lst_create_elem(&input[i] + 1));
				i = next_format_in_input(input, i + 1);
			}
			else
				i++;
		}
	}
	return ;
}
