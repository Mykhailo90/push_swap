/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:10:05 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:10:07 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

void		flags_with_a(t_str **a, t_str **b, t_help *mstr)
{
	t_str	*bptr;
	t_str	*ppt;

	bptr = *b;
	ppt = *a;
	if (ppt != NULL &&
		rotating(ppt, get_bigs(ppt, bptr->value)) == 1)
		while (ppt->value != get_bigs(ppt, bptr->value))
		{
			rotate_s1(a, mstr);
			ppt = *a;
		}
	else
		while (ppt != NULL &&
			ppt->value != get_bigs(ppt, bptr->value))
		{
			rev_rotate_a(a, mstr);
			ppt = *a;
		}
	move_s2_s1(a, b, mstr);
}

void		flags_with_b(t_str **b, t_str **a, t_help *mstr)
{
	t_str	*bptr;
	t_str	*ppt;

	bptr = *b;
	ppt = *a;
	if (bptr != NULL &&
		rotating(bptr, get_max(bptr, ppt->value)) == 1)
		while (bptr->value != get_max(bptr, ppt->value))
		{
			rotate_s2(b, mstr);
			bptr = *b;
		}
	else
		while (bptr != NULL &&
			bptr->value != get_max(bptr, ppt->value))
		{
			rev_rotate_b(b, mstr);
			bptr = *b;
		}
	move_s1_s2(a, b, mstr);
}

int			rotating(t_str *anc, int to_find)
{
	t_str	*ptr;
	int		size;
	int		help;

	help = 1;
	size = get_size(anc);
	ptr = anc;
	while (ptr != NULL)
	{
		if (ptr->value == to_find)
			break ;
		help += 1;
		ptr = ptr->next;
	}
	if (size - help < size / 2)
		return (2);
	else
		return (1);
}
