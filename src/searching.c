/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:52:07 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:52:09 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

int				get_large(t_str *anc)
{
	t_str		*ptr;
	int			max;

	ptr = anc;
	max = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value > max)
			max = ptr->value;
		ptr = ptr->next;
	}
	return (max);
}

int				get_max(t_str *b, int val)
{
	t_str		*ptr;
	int			res;

	if (val < get_min(b))
		return (get_large(b));
	ptr = b;
	res = get_min(b);
	while (ptr != NULL)
	{
		if (ptr->value > res && ptr->value < val)
			res = ptr->value;
		ptr = ptr->next;
	}
	return (res);
}

int				get_size(t_str *a)
{
	t_str		*ptr;
	int			size;

	ptr = a;
	size = 0;
	while (ptr != NULL)
	{
		size += 1;
		ptr = ptr->next;
	}
	return (size);
}

int				get_last_val(t_str *anc)
{
	int			res;
	t_str		*ptr;

	ptr = anc;
	while (ptr->next != NULL)
		ptr = ptr->next;
	res = ptr->value;
	return (res);
}

int				get_min(t_str *anc)
{
	t_str		*ptr;
	int			min;

	ptr = anc;
	min = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	return (min);
}
