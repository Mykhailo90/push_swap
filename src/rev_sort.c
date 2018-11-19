/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:51:27 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:51:28 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

void				rev_sort_q(t_str **a, t_str **b, t_help *mstr)
{
	t_str			*ppt;

	ppt = *a;
	while (ppt != NULL && !test_sorted(ppt))
	{
		set_rev_base(ppt, mstr);
		mstr->mem = ppt->value;
		rotate_s2(a, mstr);
		ppt = *a;
		palling(a, b, mstr);
		ppt = *a;
		if (ppt->value >= mstr->base)
			rev_s2_d(b, a, mstr);
		ppt = *a;
	}
}

static int			get_bigm(t_str *b, int val)
{
	t_str			*ptr;
	int				ret;

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

void				rev_s2_d(t_str **b, t_str **a, t_help *mstr)
{
	t_str			*bptr;
	t_str			*ppt;

	bptr = *b;
	ppt = *a;
	if (bptr != NULL &&
		rotating(bptr, get_bigm(bptr, ppt->value)) == 1)
		while (bptr->value != get_bigm(bptr, ppt->value))
		{
			rotate_s1(b, mstr);
			bptr = *b;
		}
	else
		while (bptr != NULL &&
			bptr->value != get_bigm(bptr, ppt->value))
		{
			rev_rotate_a(b, mstr);
			bptr = *b;
		}
	move_s2_s1(b, a, mstr);
}
