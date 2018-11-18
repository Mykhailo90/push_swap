
#include "../swaplib.h"

static void	flags(t_help *mstr, char *num, char **fname)
{
	if (ft_strcmp(num, "-o") == 0)
		mstr->output = 1;
	if (ft_strcmp(num, "-h") == 0)
		mstr->highlight = 1;
	if (ft_strcmp(num, "-v") == 0)
		mstr->visual = 1;
	if (ft_strcmp(num, "-t") == 0)
		mstr->result = 1;
	if (ft_strcmp(num, "-r") == 0 && mstr->no != 1)
	{
		printf("Enter instructions file name: ");
		while (get_next_line(1, fname) != 1)
			;
		mstr->read = open(*fname, O_RDONLY);
		free(*fname);
	}
	if (ft_strcmp(num, "-i") == 0)
	{
		mstr->input = 1;
		mstr->read = 1;
	}
}

static int	search_o(char **nums, size_t n, size_t ptr)
{
	if ((!ft_isdigit(nums[ptr][n]) && nums[ptr][n] != '+' &&
		nums[ptr][n] != '-' && ft_strcmp(nums[ptr], "-v") != 0 &&
		ft_strcmp(nums[ptr], "-o") != 0 && ft_strcmp(nums[ptr], "-t") != 0
		&& ft_strcmp(nums[ptr], "-h") != 0 && ft_strcmp(nums[ptr], "-r") != 0
		&& ft_strcmp(nums[ptr], "-i") != 0) || (ft_strcmp(nums[ptr], "-") == 0
		|| ft_strcmp(nums[ptr], "+") == 0))
		return (0);
	return (1);
}

static int	check_symb(char **x, size_t ptr)
{
	int		s;
	size_t	y;

	y = 0;
	s = 0;
	while (x[ptr][y] != '\0')
	{
		if (x[ptr][y] == '-' || x[ptr][y] == '+'){
			s += 1;
		}			
		if (!search_o(x, y++, ptr) || s > 1){
			return (0);
		}
	}
	return (1);
}

int			input_validation(char **x, t_help *mstr)
{
	size_t	ptr;
	char	*fname;

	ptr = 0;
	while (x[ptr] != 0)
	{
		if (!check_symb(x, ptr))
			return (0);
		if (ft_strcmp(x[ptr], "-v") == 0 || ft_strcmp(x[ptr], "-o") == 0 ||
			ft_strcmp(x[ptr], "-t") == 0 || ft_strcmp(x[ptr], "-h") == 0 ||
			(ft_strcmp(x[ptr], "-r") == 0 && mstr->no != 1) ||
			ft_strcmp(x[ptr], "-i") == 0)
		{
			flags(mstr, x[ptr], &fname);
			break ;
		}
		if (ft_atoi(x[ptr]) > 2147483647 ||
			ft_atoi(x[ptr]) < -2147483648)
			return (0);
		ptr += 1;
	}
	return (1);
}
