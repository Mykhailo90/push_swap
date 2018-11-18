/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_deal_with_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:02:47 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:02:48 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static int	ft_get_big(t_str *b, int val)
{
	t_str *ptr;
	int		ret;

	if (val > get_large(b))
		return (get_min(b));
	ptr = b;
	ret = get_large(b);
	while (ptr != NULL)
	{
		if (ptr->value < ret && ptr->value > val)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

void		ft_rev_deal_with_b(t_str **b, t_str **a, t_help *mstr)
{
	t_str *bptr;
	t_str *aptr;

	bptr = *b;
	aptr = *a;
	if (bptr != NULL &&
		rotating(bptr, ft_get_big(bptr, aptr->value)) == 1)
		while (bptr->value != ft_get_big(bptr, aptr->value))
		{
			rotate_s1(b, mstr);
			bptr = *b;
		}
	else
		while (bptr != NULL &&
			bptr->value != ft_get_big(bptr, aptr->value))
		{
			rev_rotate_a(b, mstr);
			bptr = *b;
		}
	move_s2_s1(b, a, mstr);
}
