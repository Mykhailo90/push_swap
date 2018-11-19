/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:53:07 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:53:09 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

static void		single(t_str **a, t_str **b, t_str *ppt, t_help *p)
{
	if (ppt->value <= p->base)
		move_s1_s2(a, b, p);
	else
		rotate_s1(a, p);
}

static void		sort_or(t_str **a, t_str **b, t_help *mstr)
{
	t_str		*ppt;

	ppt = *a;
	while (ppt->value != mstr->mem)
	{
		single(a, b, ppt, mstr);
		ppt = *a;
	}
	single(a, b, ppt, mstr);
}

void			break1(t_str **a, t_str **b, t_help *mstr, t_str **p)
{
	t_str		*ppt;

	ppt = *a;
	while (!test_sorted(*a))
	{
		mstr->base = get_base(*a, get_size(*a) / 2);
		mstr->mem = get_last_val(*a);
		sort_or(a, b, mstr);
		ppt = *a;
		add_node(make_node(get_min(*a)), p);
	}
	while (ppt->value != get_min(*a))
	{
		rotate_s1(a, mstr);
		ppt = *a;
	}
}

static void		t_o_t(t_str **a, t_str **b, t_help *mstr, t_str *p)
{
	t_str		*ppt;

	ppt = *a;
	if (search_s1_size(*a, p->value) == 2)
	{
		if (ppt->value > ppt->next->value)
			swap_s1(a, mstr);
	}
	else if (search_s1_size(*a, p->value) == 3)
		swap3(a, b, mstr);
}

void			fast_sor(t_str **a, t_str **b, t_help *mstr)
{
	t_str		*base;

	base = NULL;
	add_node(make_node(get_min(*a)), &base);
	break1(a, b, mstr, &base);
	while (get_size(*b) > 150)
	{
		break_s2(a, b, mstr, &base);
		while (search_s1_size(*a, base->value) > 3)
			break_s1(a, b, mstr, &base);
		t_o_t(a, b, mstr, base);
		del_nodes(&base);
	}
	rev_sort_q(b, a, mstr);
	while (*b)
		flags_with_a(a, b, mstr);
	final_rotate(a, mstr);
	free_list(base, 0);
}
