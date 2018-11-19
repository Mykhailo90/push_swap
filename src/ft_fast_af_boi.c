/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sor.c                                   :+:      :+:    :+:   */
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
	if (search_s1_size(*a, p->value) == 2)
	{
		if (aptr->value > aptr->next->value)
			swap_s1(a, mstr);
	}
	else if (search_s1_size(*a, p->value) == 3)
		swap3(a, b, mstr);
}

void		fast_sor(t_str **a, t_str **b, t_help *mstr)
{
	t_str	*base;

	base = NULL;
	add_node(make_node(get_min(*a)), &base);
	break1(a, b, mstr, &base);
	while (get_size(*b) > 150)
	{
		break_s2(a, b, mstr, &base);
		while (search_s1_size(*a, base->value) > 3)
			break_s1(a, b, mstr, &base);
		ft_two_or_three(a, b, mstr, base);
		del_nodes(&base);
	}
	rev_sort_q(b, a, mstr);
	while (*b)
		flags_with_a(a, b, mstr);
	final_rotate(a, mstr);
	free_list(base, 0);
}
