/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:10:48 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:10:50 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

int				free_arr(char **nums, int ret)
{
	size_t		ptr;

	ptr = 0;
	while (nums[ptr] != 0)
	{
		free(nums[ptr]);
		ptr += 1;
	}
	free(nums);
	return (ret);
}

void			del_nodes(t_str **anc)
{
	t_str		*ptr;

	ptr = *anc;
	*anc = ptr->next;
	free(ptr);
}

void			free_list(t_str *a, t_str *b)
{
	t_str		*ptr;
	t_str		*next;

	ptr = a;
	while (ptr != NULL)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	ptr = b;
	while (ptr != NULL)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
}
