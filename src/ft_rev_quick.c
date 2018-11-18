/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_quick_sort.c                                :+:      :+:    :+:   */
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
	int		(*f_g)(t_str *node, int mem, int pivot);

	ap = *a;
	bp = *b;
	f_b = &get_bigs;
	f_g = &next_val;
	while (ap->value != p->mem)
	{
		if (ap->value >= p->pivot)
			ft_rev_deal_with_b(b, a, p);
		else
		{
			if (bp != NULL && vallet(ap, p->mem, p->pivot) &&
				rotating(bp, f_b(bp, f_g(ap, p->mem, p->pivot))) == 1
				&& bp->value != f_b(bp, f_g(ap, p->mem, p->pivot)))
				rotate_both(a, b, p);
			else
				rotate_s2(a, p);
		}
		ap = *a;
		bp = *b;
	}
}

void		ft_rev_quick_sort(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;
	t_str *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr != NULL && !test_sorted(aptr))
	{
		set_rev_base(aptr, mstr);
		mstr->mem = aptr->value;
		rotate_s2(a, mstr);
		aptr = *a;
		ft_pall(a, b, mstr);
		aptr = *a;
		bptr = *b;
		if (aptr->value >= mstr->pivot)
			ft_rev_deal_with_b(b, a, mstr);
		aptr = *a;
		bptr = *b;
	}
}