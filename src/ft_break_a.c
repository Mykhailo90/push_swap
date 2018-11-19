/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_s1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:38:13 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/03/05 16:38:13 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	rotate_s2ack(t_str **a, t_help *mstr)
{
	if (rotating(*a, mstr->mem) == 1)
		while (get_last_val(*a) != mstr->mem)
			rotate_s1(a, mstr);
	else
		while (get_last_val(*a) != mstr->mem)
			rev_rotate_a(a, mstr);
}

void		break_s1(t_str **a, t_str **b, t_help *mstr, t_str **base)
{
	t_str *aptr;
	t_str *pivptr;

	aptr = *a;
	pivptr = *base;
	mstr->base = make_new_base(*a, search_next_s1(*a, pivptr->value));
	mstr->mem = get_last_val(*a);
	while (aptr->value <= pivptr->value &&
		left_s1(*a, pivptr->value, mstr->base))
	{
		if (aptr->value <= mstr->base)
			move_s1_s2(a, b, mstr);
		else
			rotate_s1(a, mstr);
		aptr = *a;
	}
	if (aptr->value <= mstr->base)
		move_s1_s2(a, b, mstr);
	aptr = *a;
	rotate_s2ack(a, mstr);
	add_next(make_node(mstr->base), base);
}
