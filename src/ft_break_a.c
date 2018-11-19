/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_a.c                                       :+:      :+:    :+:   */
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

void		ft_break_a(t_str **a, t_str **b, t_help *mstr, t_str **pivots)
{
	t_str *aptr;
	t_str *pivptr;

	aptr = *a;
	pivptr = *pivots;
	mstr->pivot = make_new_base(*a, ft_find_next_a(*a, pivptr->value));
	mstr->mem = get_last_val(*a);
	while (aptr->value <= pivptr->value &&
		ft_is_left_a(*a, pivptr->value, mstr->pivot))
	{
		if (aptr->value <= mstr->pivot)
			move_s1_s2(a, b, mstr);
		else
			rotate_s1(a, mstr);
		aptr = *a;
	}
	if (aptr->value <= mstr->pivot)
		move_s1_s2(a, b, mstr);
	aptr = *a;
	rotate_s2ack(a, mstr);
	add_next(make_node(mstr->pivot), pivots);
}
