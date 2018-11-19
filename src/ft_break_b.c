/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_s2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:36:26 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/03/05 16:36:27 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_lil_to_a(t_str **a, t_str **b, t_str *p, t_help *mstr)
{
	t_str *bptr;

	bptr = *b;
	while (bptr->value >= p->next->value)
	{
		move_s2_s1(a, b, mstr);
		bptr = *b;
	}
	if (rotating(*b, mstr->mem) == 1)
		while (get_last_val(*b) != mstr->mem)
			rotate_s2(b, mstr);
	else
		while (get_last_val(*b) != mstr->mem)
			rev_rotate_b(b, mstr);
}

static void	ft_p_or_r_b(t_str **a, t_str **b, t_help *mstr, t_str *pivptr)
{
	t_str *bptr;

	bptr = *b;
	while (bptr->value >= pivptr->next->value && bptr->value != mstr->mem
		&& left_check(*b, pivptr->next->value, mstr->base, mstr->mem))
	{
		if (bptr->value >= mstr->base)
			move_s2_s1(a, b, mstr);
		else
			rotate_s2(b, mstr);
		bptr = *b;
	}
	if (bptr->value >= mstr->base)
	{
		mstr->mem = bptr->next->value;
		move_s2_s1(a, b, mstr);
	}
}

void		break_s2(t_str **a, t_str **b, t_help *mstr, t_str **base)
{
	t_str *pivptr;

	pivptr = *base;
	mstr->mem = get_last_val(*b);
	if (search_size(*b, pivptr->next->value) > 3)
	{
		mstr->base = make_new_base(*b, next_search(*b, pivptr->next->value));
		ft_p_or_r_b(a, b, mstr, pivptr);
		if (rotating(*b, mstr->mem) == 1)
			while (get_last_val(*b) != mstr->mem)
				rotate_s2(b, mstr);
		else
			while (get_last_val(*b) != mstr->mem)
				rev_rotate_b(b, mstr);
		add_next(make_node(mstr->base), base);
	}
	else
		ft_lil_to_a(a, b, pivptr, mstr);
}
