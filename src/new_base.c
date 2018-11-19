/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:49:55 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:49:56 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

static int	size_of_part(t_str *a, int tx)
{
	int		ret;
	t_str	*ptr;

	ret = 0;
	ptr = a;
	while (ptr->value != tx)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

static int	min_part(t_str *a, int tx)
{
	int		ret;
	t_str	*ptr;

	ptr = a;
	ret = ptr->value;
	while (ptr->value != tx)
	{
		if (ptr->value < ret)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

static int	max_part(t_str *a, int tx)
{
	int		ret;
	t_str	*ptr;

	ptr = a;
	ret = ptr->value;
	while (ptr->value != tx)
	{
		if (ptr->value > ret)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

int			make_new_base(t_str *a, int tx)
{
	int		count;
	int		res;
	int		x;
	t_str	*ptr;

	count = 0;
	ptr = a;
	x = min_part(a, tx);
	res = max_part(a, tx);
	while (count < (size_of_part(a, tx) / 2))
	{
		ptr = a;
		res = max_part(a, tx);
		while (ptr->value != tx)
		{
			if (ptr->value < res && ptr->value > x)
				res = ptr->value;
			ptr = ptr->next;
		}
		x = res;
		count += 1;
	}
	return (res);
}
