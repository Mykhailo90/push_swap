/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:22:05 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/24 18:22:06 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static int	ft_build_stack(t_str **a, t_help *mstr, char **argv, int argc)
{
	char	**nums;

	mstr->add = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (nums[0] == 0)
		return (free_arr(nums, 0));
	if (!input_validation(nums, mstr))
		return (free_arr(nums, 1));
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0
		|| ft_strcmp(nums[0], "-t") == 0 || ft_strcmp(nums[0], "-h") == 0
		|| ft_strcmp(nums[0], "-r") == 0 || ft_strcmp(nums[0], "-i") == 0)
		return (free_arr(nums, 0));
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

static void	ft_apply(char *line, t_str **a, t_str **b, t_help *mstr)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_s1(a, mstr);
	if (ft_strcmp(line, "sb") == 0)
		swap_s2(b, mstr);
	if (ft_strcmp(line, "ss") == 0)
		swap_both(a, b, mstr);
	if (ft_strcmp(line, "pa") == 0)
		move_s2_s1(a, b, mstr);
	if (ft_strcmp(line, "pb") == 0)
		move_s1_s2(a, b, mstr);
	if (ft_strcmp(line, "ra") == 0)
		rotate_s1(a, mstr);
	if (ft_strcmp(line, "rb") == 0)
		rotate_s2(b, mstr);
	if (ft_strcmp(line, "rr") == 0)
		rotate_both(a, b, mstr);
	if (ft_strcmp(line, "rra") == 0)
		rev_rotate_a(a, mstr);
	if (ft_strcmp(line, "rrb") == 0)
		rev_rotate_b(b, mstr);
	if (ft_strcmp(line, "rrr") == 0)
		rev_rotate_both(a, b, mstr);
}

static void	ft_assign(t_help *mstr, t_str **a, t_str **b, int *fd)
{
	*a = NULL;
	*b = NULL;
	*fd = -1;
	mstr->total = 0;
	mstr->print = 0;
	mstr->visual = 0;
	mstr->output = 0;
	mstr->result = 0;
	mstr->highlight = 0;
	mstr->read = 0;
	mstr->input = 0;
	mstr->no = 0;
}

int			main(int argc, char **argv)
{
	t_str	*a;
	t_str	*b;
	char	*line;
	t_help	mstr;
	int		fd;

	ft_assign(&mstr, &a, &b, &fd);
	config(argv, argc, &mstr);
	while (mstr.ac > 1)
		if (ft_build_stack(&a, &mstr, argv, mstr.ac--) || mstr.read == -1)
			return (pars_error(argc));
	if (argc < 2 || get_size(a) == 0 || !ft_check_unique(a))
		return (pars_error(argc));
	start_print(&mstr, &fd, a, b);
	while (mstr.add != 0)
	{
		if (pars_inst(&mstr, &line))
			return (pars_error(argc));
		ft_apply(line, &a, &b, &mstr);
		stack_visual(mstr, line, a, b);
		if (mstr.output == 1 && ft_strlen(line))
			ft_putendl_fd(line, fd);
		free(line);
	}
	return (print_result(mstr, fd, a, b));
}
