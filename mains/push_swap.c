/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:14:23 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/22 17:14:48 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_swap_rotate(t_str **a, t_help *mstr)
{
	t_str *ptr;

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

static int	ft_build_stack(t_str **a, t_help *mstr, char **argv, int argc)
{
	char	**nums;

	mstr->add = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (nums[0] == 0)
		free_arr(nums, 0);
	if (!input_validation(nums, mstr))
		free_arr(nums, 1);
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0
		|| ft_strcmp(nums[0], "-t") == 0 || ft_strcmp(nums[0], "-h") == 0
		|| ft_strcmp(nums[0], "-r") == 0 || ft_strcmp(nums[0], "-i") == 0)
		free_arr(nums, 0);
	while (nums[mstr->add] != 0)
		mstr->add += 1;
	mstr->add -= 1;
	while (mstr->add >= 0)
	{
		add_node(make_node(ft_atoi(nums[mstr->add])), a);
		mstr->add -= 1;
	}
	return (free_arr(nums, 0));
}

static int	ft_check_unique(t_str *a)
{
	t_str *ptr;
	int		mem;

	while (a != NULL)
	{
		mem = a->value;
		ptr = a;
		while (ptr != NULL)
		{
			ptr = ptr->next;
			if (ptr != NULL && ptr->value == mem)
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
	mstr.total = 0;
	mstr.print = 1;
	mstr.visual = 0;
	mstr.ac = argc;
	while (mstr.ac > 1)
		if (ft_build_stack(&a, &mstr, argv, mstr.ac--))
			return (pars_error(argc));
	if (argc < 2 || get_size(a) == 0 || !ft_check_unique(a))
		return (pars_error(argc));
	if (get_size(a) <= 3)
		ft_swap_rotate(&a, &mstr);
	else if (get_size(a) <= 10)
		ft_insert_swap(&a, &b, &mstr);
	else if (get_size(a) <= 100)
		ft_quick_sort(&a, &b, &mstr);
	else
		ft_fast_af_boi(&a, &b, &mstr);
	free_list(a, b);
	return (0);
}
