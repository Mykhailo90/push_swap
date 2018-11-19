/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:51:50 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:51:51 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

void	rotate_s2(t_str **b, t_help *mstr)
{
	rotate(&*b);
	mstr->sum += 1;
	if (mstr->pr == 1)
		printf("rb\n");
}

void	rotate_both(t_str **a, t_str **b, t_help *mstr)
{
	rotate(&*a);
	rotate(&*b);
	if (mstr->pr == 1)
		printf("rr\n");
	mstr->sum += 1;
}

void	rev_rotate_both(t_str **a, t_str **b, t_help *mstr)
{
	rev_rotate(&*a);
	rev_rotate(&*b);
	if (mstr->pr == 1)
		printf("rrr\n");
	mstr->sum += 1;
}

void	final_rotate(t_str **a, t_help *mstr)
{
	t_str *ppt;

	ppt = *a;
	if (rotating(ppt, get_min(ppt)) == 1)
		while (ppt->value != get_min(ppt))
		{
			rotate_s1(a, mstr);
			ppt = *a;
		}
	else
		while (ppt->value != get_min(ppt))
		{
			rev_rotate_a(a, mstr);
			ppt = *a;
		}
}
