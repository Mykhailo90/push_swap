
#include "../push_swaplib.h"

int	build_st(t_str **a, t_help *mstr, char **argv, int argc)
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
