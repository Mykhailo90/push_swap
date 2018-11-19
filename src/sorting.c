/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:53:35 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:53:37 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

void	sorting(t_str **a, t_str **b, t_help *mstr)
{
	t_str *ppt;
	t_str *bptr;

	ppt = *a;
	bptr = *b;
	while (ppt->next != NULL && ppt->value != get_min(ppt))
	{
		rotate_s1(a, mstr);
		ppt = *a;
	}
	while (bptr != NULL)
	{
		move_s2_s1(a, b, mstr);
		bptr = *b;
	}
}
