/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_q.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:02:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:02:14 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	get_bigs(t_str *b, int val)
{
	t_str *ptr;
	int		ret;

	if (val > get_large(b))
		return (get_min(b));
	ptr = b;
	ret = get_large(b);
	while (ptr != NULL)
	{
		if (ptr->value < ret && ptr->value > val)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

static void	ft_pall(t_str **a, t_str **b, t_help *p)
{
	t_str *ap;
	t_str *bp;

	int		(*f_b)(t_str *b, int val);
	int		(*f_g)(t_str *node, int mem, int base);

	ap = *a;
	bp = *b;
	f_g = &next_val;
	f_b = &get_bigs;
	
	while (ap->value != p->mem)
	{
		if (ap->value <= p->base)
			flags_with_b(b, a, p);
		else
		{
			if (bp != NULL && vallet(ap, p->mem, p->base) &&
				rotating(bp, f_b(bp, f_g(ap, p->mem, p->base))) == 1
				&& bp->value != f_b(bp, f_g(ap, p->mem, p->base)))
				rotate_both(a, b, p);
			else
				rotate_s1(a, p);
		}
		ap = *a;
		bp = *b;
	}
}

static void	ft_shmatochok(t_str **a, t_str **b, t_help *mstr)
{
	t_str *bptr;

	bptr = *b;
	if (rotating(bptr, get_large(bptr)) == 1)
		while (bptr->value != get_large(bptr))
		{
			rotate_s2(b, mstr);
			bptr = *b;
		}
	else
		while (bptr->value != get_large(bptr))
		{
			rev_rotate_b(b, mstr);
			bptr = *b;
		}
	bptr = *a;
}

void		sort_q(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;

	aptr = *a;
	while (aptr != NULL && !test_sorted(aptr))
	{
		set_base(aptr, mstr);
		mstr->mem = aptr->value;
		rotate_s1(a, mstr);
		aptr = *a;
		ft_pall(a, b, mstr);
		aptr = *a;
		if (aptr->value <= mstr->base)
			flags_with_b(b, a, mstr);
		ft_shmatochok(a, b, mstr);
		aptr = *a;
	}
	sorting(a, b, mstr);
}
