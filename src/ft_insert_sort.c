/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:03:13 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:03:34 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_get_to_unsorted(t_str **a, int *mem, t_help *mstr)
{
	t_str *aptr;

	aptr = *a;
	if (search_unsort(aptr, get_min(aptr), get_large(aptr), mem) == 1)
		while (aptr->value != *mem)
		{
			rotate_s1(a, mstr);
			aptr = *a;
		}
	else
		while (aptr->value != *mem)
		{
			rev_rotate_a(a, mstr);
			aptr = *a;
		}
}

static void	ft_if_max(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;
	t_str *bptr;

	aptr = *a;
	bptr = *b;
	if (aptr->next->next->value == get_min(aptr) &&
		aptr->next->value > get_last_val(aptr))
		swap_s1(a, mstr);
	else if (aptr->next->next->value == get_min(aptr))
	{
		rotate_s1(a, mstr);
		swap_s1(a, mstr);
	}
	else
	{
		rotate_s1(a, mstr);
		aptr = *a;
		while (aptr->value != get_min(aptr))
		{
			move_s1_s2(a, b, mstr);
			aptr = *a;
			bptr = *b;
		}
	}
	aptr = *a;
}

static void	ft_for_no_max(t_str **a, t_str **b, t_help *mstr, int mem)
{
	t_str *aptr;
	t_str *bptr;

	aptr = *a;
	bptr = *b;
	if (aptr->value < aptr->next->next->value &&
		(aptr->next->value > get_last_val(aptr) ||
			(aptr->next->value == get_min(aptr) &&
				get_last_val(aptr) == get_large(aptr))))
	{
		swap_s1(a, mstr);
		aptr = *a;
	}
	else
	{
		rotate_s1(a, mstr);
		aptr = *a;
		while (aptr->value < mem)
		{
			move_s1_s2(a, b, mstr);
			aptr = *a;
			bptr = *b;
		}
	}
}

static void	ft_empty_b(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;
	t_str *bptr;

	aptr = *a;
	bptr = *b;
	while (bptr != NULL)
	{
		if (rotating(aptr, get_max(aptr, bptr->value)) == 1)
			while (get_last_val(aptr) !=
				get_max(aptr, bptr->value))
			{
				rotate_s1(a, mstr);
				aptr = *a;
			}
		else
			while (get_last_val(aptr) !=
				get_max(aptr, bptr->value))
			{
				rev_rotate_a(a, mstr);
				aptr = *a;
			}
		move_s2_s1(a, b, mstr);
		aptr = *a;
		bptr = *b;
	}
}

void		ft_insert_swap(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;
	t_str	*bptr;
	int		mem;

	aptr = *a;
	bptr = *b;
	while (!test_sorted(aptr))
	{
		ft_get_to_unsorted(a, &mem, mstr);
		aptr = *a;
		if (aptr->value == get_large(aptr))
			ft_if_max(a, b, mstr);
		else
			ft_for_no_max(a, b, mstr, mem);
		aptr = *a;
	}
	ft_empty_b(a, b, mstr);
	final_rotate(a, mstr);
}
