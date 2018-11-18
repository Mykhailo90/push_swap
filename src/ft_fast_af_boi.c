/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_af_boi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:29:36 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/21 14:29:36 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_two_or_three(t_str **a, t_str **b, t_help *mstr, t_str *p)
{
	t_str *aptr;

	aptr = *a;
	if (ft_find_size_a(*a, p->value) == 2)
	{
		if (aptr->value > aptr->next->value)
			swap_s1(a, mstr);
	}
	else if (ft_find_size_a(*a, p->value) == 3)
		ft_swap_three(a, b, mstr);
}

void		ft_fast_af_boi(t_str **a, t_str **b, t_help *mstr)
{
	t_str	*aptr;
	t_str	*bptr;
	t_str	*pivots;

	pivots = NULL;
	add_node(make_node(get_min(*a)), &pivots);
	ft_first_break(a, b, mstr, &pivots);
	while (get_size(*b) > 150)
	{
		ft_break_b(a, b, mstr, &pivots);
		while (ft_find_size_a(*a, pivots->value) > 3)
			ft_break_a(a, b, mstr, &pivots);
		ft_two_or_three(a, b, mstr, pivots);
		aptr = *a;
		bptr = *b;
		ft_del_node(&pivots);
	}
	ft_rev_quick_sort(b, a, mstr);
	while (*b)
		flags_with_a(a, b, mstr);
	final_rotate(a, mstr);
	free_list(pivots, 0);
}
