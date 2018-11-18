/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:33:12 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/03/05 16:33:13 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_find_size(t_str *b, int pivot)
{
	int		ret;
	t_str	*ptr;

	ret = 0;
	ptr = b;
	while (ptr->next && ptr->value >= pivot)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int	ft_find_size_a(t_str *a, int pivot)
{
	int		ret;
	t_str	*ptr;

	ret = 0;
	ptr = a;
	while (ptr->next && ptr->value <= pivot)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int	ft_find_next(t_str *b, int pivot)
{
	t_str *ptr;

	ptr = b;
	while (ptr->next && ptr->value >= pivot)
		ptr = ptr->next;
	return (ptr->value);
}

int	ft_find_next_a(t_str *a, int pivot)
{
	t_str *ptr;

	ptr = a;
	while (ptr->next && ptr->value < pivot)
		ptr = ptr->next;
	return (ptr->value);
}

int	next_val(t_str *node, int x, int base)
{
	t_str *ptr;

	ptr = node;
	while (ptr->value != x)
	{
		if (ptr->value < base)
			break ;
		ptr = ptr->next;
	}
	return (ptr->value);
}
