/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:02:50 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/19 20:02:52 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swaplib.h"

void		rotate_swap(t_str **a, t_help *mstr)
{
	t_str	*ptr;

	ptr = *a;
	if (!test_sorted(ptr))
		swap_s1(a, mstr);
	ptr = *a;
	if (rotating(ptr, get_min(ptr)) == 1)
		while (ptr->value != get_min(ptr))
		{
			rotate_s1(a, mstr);
			ptr = *a;
		}
	else
		while (ptr->value != get_min(ptr))
		{
			rev_rotate_a(a, mstr);
			ptr = *a;
		}
}

int			build_st(t_str **a, t_help *mstr, char **argv, int argc)
{
	char	**nums;

	mstr->plus = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (nums[0] == 0)
		free_arr(nums, 0);
	if (!input_validation(nums, mstr))
		free_arr(nums, 1);
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0
		|| ft_strcmp(nums[0], "-t") == 0 || ft_strcmp(nums[0], "-h") == 0
		|| ft_strcmp(nums[0], "-r") == 0 || ft_strcmp(nums[0], "-i") == 0)
		free_arr(nums, 0);
	while (nums[mstr->plus] != 0)
		mstr->plus += 1;
	mstr->plus -= 1;
	while (mstr->plus >= 0)
	{
		add_node(make_node(ft_atoi(nums[mstr->plus])), a);
		mstr->plus -= 1;
	}
	return (free_arr(nums, 0));
}

int			unique(t_str *a)
{
	t_str	*ptr;
	int		x;

	while (a != NULL)
	{
		x = a->value;
		ptr = a;
		while (ptr != NULL)
		{
			ptr = ptr->next;
			if (ptr != NULL && ptr->value == x)
				return (0);
		}
		a = a->next;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_str	*a;
	t_str	*b;
	t_help	mstr;

	a = NULL;
	b = NULL;
	mstr.sum = 0;
	mstr.pr = 1;
	mstr.visual = 0;
	mstr.ac = argc;
	while (mstr.ac > 1)
		if (build_st(&a, &mstr, argv, mstr.ac--))
			return (pars_error(argc));
	if (argc < 2 || get_size(a) == 0 || !unique(a))
		return (pars_error(argc));
	if (get_size(a) <= 3)
		rotate_swap(&a, &mstr);
	else if (get_size(a) <= 10)
		swapins(&a, &b, &mstr);
	else if (get_size(a) <= 100)
		sort_q(&a, &b, &mstr);
	else
		fast_sor(&a, &b, &mstr);
	free_list(a, b);
	return (0);
}
