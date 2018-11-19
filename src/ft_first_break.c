/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_break.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:34:20 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/03/05 16:34:21 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_loop_single(t_str **a, t_str **b, t_str *aptr, t_help *p)
{
	if (aptr->value <= p->pivot)
		move_s1_s2(a, b, p);
	else
		rotate_s1(a, p);
}

static void	ft_p_or_r_a(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;

	aptr = *a;
	while (aptr->value != mstr->mem)
	{
		ft_loop_single(a, b, aptr, mstr);
		aptr = *a;
	}
	ft_loop_single(a, b, aptr, mstr);
}

void		ft_first_break(t_str **a, t_str **b, t_help *mstr, t_str **p)
{
	t_str *aptr;

	aptr = *a;
	while (!test_sorted(*a))
	{
		mstr->pivot = get_base(*a, get_size(*a) / 2);
		mstr->mem = get_last_val(*a);
		ft_p_or_r_a(a, b, mstr);
		aptr = *a;
		add_node(make_node(get_min(*a)), p);
	}
	while (aptr->value != get_min(*a))
	{
		rotate_s1(a, mstr);
		aptr = *a;
	}
}
