/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_b.c                                       :+:      :+:    :+:   */
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
		&& ft_is_left(*b, pivptr->next->value, mstr->pivot, mstr->mem))
	{
		if (bptr->value >= mstr->pivot)
			move_s2_s1(a, b, mstr);
		else
			rotate_s2(b, mstr);
		bptr = *b;
	}
	if (bptr->value >= mstr->pivot)
	{
		mstr->mem = bptr->next->value;
		move_s2_s1(a, b, mstr);
	}
}

void		ft_break_b(t_str **a, t_str **b, t_help *mstr, t_str **pivots)
{
	t_str *aptr;
	t_str *bptr;
	t_str *pivptr;

	aptr = *a;
	bptr = *b;
	pivptr = *pivots;
	mstr->mem = get_last_val(*b);
	if (ft_find_size(*b, pivptr->next->value) > 3)
	{
		mstr->pivot = make_new_base(*b, ft_find_next(*b, pivptr->next->value));
		ft_p_or_r_b(a, b, mstr, pivptr);
		if (rotating(*b, mstr->mem) == 1)
			while (get_last_val(*b) != mstr->mem)
				rotate_s2(b, mstr);
		else
			while (get_last_val(*b) != mstr->mem)
				rev_rotate_b(b, mstr);
		aptr = *a;
		bptr = *b;
		add_next(make_node(mstr->pivot), pivots);
	}
	else
		ft_lil_to_a(a, b, pivptr, mstr);
}
