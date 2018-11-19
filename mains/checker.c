
#include "../swaplib.h"

static int	build_st(t_str **a, t_help *mstr, char **argv, int argc)
{
	char	**nums;

	mstr->plus = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (nums[0] == 0)
		return (free_arr(nums, 0));
	if (!input_validation(nums, mstr))
		return (free_arr(nums, 1));
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0
		|| ft_strcmp(nums[0], "-t") == 0 || ft_strcmp(nums[0], "-h") == 0
		|| ft_strcmp(nums[0], "-r") == 0 || ft_strcmp(nums[0], "-i") == 0)
		return (free_arr(nums, 0));
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

int	unique_check(t_str *a)
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

void	initialize(t_help *mstr, t_str **a, t_str **b, int *fd)
{
	*a = NULL;
	*b = NULL;
	*fd = -1;
	
	mstr->hl = 0;
	mstr->input = 0;
	mstr->not = 0;
	mstr->out = 0;
	mstr->pr = 0;
	mstr->res = 0;
	mstr->read = 0;
	mstr->sum = 0;
	mstr->visual = 0;
}

int			main(int argc, char **argv)
{
	t_str	*a;
	t_str	*b;
	char	*line;
	t_help	mstr;
	int		fd;

	initialize(&mstr, &a, &b, &fd);
	config(argv, argc, &mstr);
	while (mstr.ac > 1)
		if (build_st(&a, &mstr, argv, mstr.ac--) || mstr.read == -1)
			return (pars_error(argc));
	if (argc < 2 || get_size(a) == 0 || !unique_check(a))
		return (pars_error(argc));
	start_print(&mstr, &fd, a, b);
	while (mstr.plus != 0)
	{
		if (pars_inst(&mstr, &line))
			return (pars_error(argc));
		ft_apply(line, &a, &b, &mstr);
		stack_visual(mstr, line, a, b);
		if (mstr.out == 1 && ft_strlen(line))
			ft_putendl_fd(line, fd);
		free(line);
	}
	return (print_result(mstr, fd, a, b));
}
