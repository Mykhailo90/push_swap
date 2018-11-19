/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:52:57 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:52:58 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

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
	t_str *ppt;
	t_str *pivptr;

	ppt = *a;
	pivptr = *base;
	mstr->base = make_new_base(*a, search_next_s1(*a, pivptr->value));
	mstr->mem = get_last_val(*a);
	while (ppt->value <= pivptr->value &&
		left_s1(*a, pivptr->value, mstr->base))
	{
		if (ppt->value <= mstr->base)
			move_s1_s2(a, b, mstr);
		else
			rotate_s1(a, mstr);
		ppt = *a;
	}
	if (ppt->value <= mstr->base)
		move_s1_s2(a, b, mstr);
	ppt = *a;
	rotate_s2ack(a, mstr);
	add_next(make_node(mstr->base), base);
}
