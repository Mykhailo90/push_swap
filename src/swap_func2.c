/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:54:02 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:54:03 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

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

void		swap3(t_str **a, t_str **b, t_help *mstr)
{
	t_str	*ptr;
	int		min;
	int		max;

	ptr = *a;
	min = min_s(*a);
	max = max_s(*a);
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
