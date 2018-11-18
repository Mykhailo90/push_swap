/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:29:29 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/03/05 16:29:30 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_for_321(t_str **a, t_str **b, t_help *mstr)
{
	move_s1_s2(a, b, mstr);
	swap_s1(a, mstr);
	rotate_s1(a, mstr);
	rotate_s1(a, mstr);
	move_s2_s1(a, b, mstr);
	rev_rotate_a(a, mstr);
	rev_rotate_a(a, mstr);
}

static void	ft_for_213(t_str **a, t_str **b, t_help *mstr)
{
	move_s1_s2(a, b, mstr);
	rotate_s1(a, mstr);
	rotate_s1(a, mstr);
	move_s2_s1(a, b, mstr);
	rev_rotate_a(a, mstr);
	rev_rotate_a(a, mstr);
}

static void	ft_for_231_132(t_str **a, t_str **b, t_help *mstr, int min)
{
	t_str *ptr;

	ptr = *a;
	if (ptr->value == min)
	{
		rotate_s1(a, mstr);
		swap_s1(a, mstr);
		rev_rotate_a(a, mstr);
	}
	else
	{
		move_s1_s2(a, b, mstr);
		swap_s1(a, mstr);
		rotate_s1(a, mstr);
		move_s2_s1(a, b, mstr);
		rev_rotate_a(a, mstr);
	}
}

static void	ft_for_312_213(t_str **a, t_str **b, t_help *mstr, int max)
{
	t_str *ptr;

	ptr = *a;
	if (ptr->value != max)
		swap_s1(a, mstr);
	else
	{
		move_s1_s2(a, b, mstr);
		rotate_s1(a, mstr);
		rotate_s1(a, mstr);
		move_s2_s1(a, b, mstr);
		rev_rotate_a(a, mstr);
		rev_rotate_a(a, mstr);
	}
}

void		ft_swap_three(t_str **a, t_str **b, t_help *mstr)
{
	t_str *ptr;
	int		min;
	int		max;

	ptr = *a;
	min = ft_min(*a);
	max = ft_max(*a);
	if (ptr->value > ptr->next->value ||
		ptr->next->value > ptr->next->next->value)
	{
		if (ptr->value > ptr->next->value && ptr->next->value <
			ptr->next->next->value)
			ft_for_312_213(a, b, mstr, max);
		else if (ptr->value < ptr->next->value &&
			ptr->next->value > ptr->next->next->value)
			ft_for_231_132(a, b, mstr, min);
		else if (ptr->value > ptr->next->value &&
			ptr->next->value < ptr->next->next->value)
			ft_for_213(a, b, mstr);
		else if (ptr->value > ptr->next->value &&
			ptr->next->value > ptr->next->next->value)
			ft_for_321(a, b, mstr);
	}
}
