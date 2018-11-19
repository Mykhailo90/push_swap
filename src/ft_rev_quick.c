/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort_q.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:02:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:02:14 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"



static void	ft_pall(t_str **a, t_str **b, t_help *p)
{
	t_str *ap;
	t_str *bp;
	int		(*f_b)(t_str *b, int val);
	int		(*f_g)(t_str *node, int mem, int base);

	ap = *a;
	bp = *b;
	f_b = &get_bigs;
	f_g = &next_val;
	while (ap->value != p->mem)
	{
		if (ap->value >= p->base)
			rev_s2_d(b, a, p);
		else
		{
			if (bp != NULL && vallet(ap, p->mem, p->base) &&
				rotating(bp, f_b(bp, f_g(ap, p->mem, p->base))) == 1
				&& bp->value != f_b(bp, f_g(ap, p->mem, p->base)))
				rotate_both(a, b, p);
			else
				rotate_s2(a, p);
		}
		ap = *a;
		bp = *b;
	}
}

void		rev_sort_q(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;

	aptr = *a;
	while (aptr != NULL && !test_sorted(aptr))
	{
		set_rev_base(aptr, mstr);
		mstr->mem = aptr->value;
		rotate_s2(a, mstr);
		aptr = *a;
		ft_pall(a, b, mstr);
		aptr = *a;
		if (aptr->value >= mstr->base)
			rev_s2_d(b, a, mstr);
		aptr = *a;
	}
}
