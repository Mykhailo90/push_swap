/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:53:15 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:53:17 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

static void		get_uns(t_str **a, int *mem, t_help *mstr)
{
	t_str		*ppt;

	ppt = *a;
	if (search_unsort(ppt, get_min(ppt), get_large(ppt), mem) == 1)
		while (ppt->value != *mem)
		{
			rotate_s1(a, mstr);
			ppt = *a;
		}
	else
		while (ppt->value != *mem)
		{
			rev_rotate_a(a, mstr);
			ppt = *a;
		}
}

static void		maxi_check(t_str **a, t_str **b, t_help *mstr)
{
	t_str		*ppt;

	ppt = *a;
	if (ppt->next->next->value == get_min(ppt) &&
		ppt->next->value > get_last_val(ppt))
		swap_s1(a, mstr);
	else if (ppt->next->next->value == get_min(ppt))
	{
		rotate_s1(a, mstr);
		swap_s1(a, mstr);
	}
	else
	{
		rotate_s1(a, mstr);
		ppt = *a;
		while (ppt->value != get_min(ppt))
		{
			move_s1_s2(a, b, mstr);
			ppt = *a;
		}
	}
	ppt = *a;
}

static void		not_maxi(t_str **a, t_str **b, t_help *mstr, int mem)
{
	t_str		*ppt;

	ppt = *a;
	if (ppt->value < ppt->next->next->value &&
		(ppt->next->value > get_last_val(ppt) ||
			(ppt->next->value == get_min(ppt) &&
				get_last_val(ppt) == get_large(ppt))))
	{
		swap_s1(a, mstr);
		ppt = *a;
	}
	else
	{
		rotate_s1(a, mstr);
		ppt = *a;
		while (ppt->value < mem)
		{
			move_s1_s2(a, b, mstr);
			ppt = *a;
		}
	}
}

static void		empty_s2(t_str **a, t_str **b, t_help *mstr)
{
	t_str		*ppt;
	t_str		*bptr;

	ppt = *a;
	bptr = *b;
	while (bptr != NULL)
	{
		if (rotating(ppt, get_max(ppt, bptr->value)) == 1)
			while (get_last_val(ppt) !=
				get_max(ppt, bptr->value))
			{
				rotate_s1(a, mstr);
				ppt = *a;
			}
		else
			while (get_last_val(ppt) !=
				get_max(ppt, bptr->value))
			{
				rev_rotate_a(a, mstr);
				ppt = *a;
			}
		move_s2_s1(a, b, mstr);
		ppt = *a;
		bptr = *b;
	}
}

void			swapins(t_str **a, t_str **b, t_help *mstr)
{
	t_str		*ppt;
	int			x;

	ppt = *a;
	while (!test_sorted(ppt))
	{
		get_uns(a, &x, mstr);
		ppt = *a;
		if (ppt->value == get_large(ppt))
			maxi_check(a, b, mstr);
		else
			not_maxi(a, b, mstr, x);
		ppt = *a;
	}
	empty_s2(a, b, mstr);
	final_rotate(a, mstr);
}
