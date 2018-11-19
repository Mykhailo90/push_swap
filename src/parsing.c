
#include "../swaplib.h"

void	config(char **argv, int argc, t_help *mstr)
{
	mstr->ac = argc;
	while (argc != 1)
	{
		if (ft_strcmp(argv[argc - 1], "-i") == 0)
			mstr->not = 1;
		argc -= 1;
	}
}

int	pars_inst(t_help *mstr, char **line)
{
	if (mstr->input == 1)
		printf("Instruction: ");
	mstr->plus = get_next_line(mstr->read, line);
	if (mstr->input == 1 && *line[0] == '\0')
		printf("\n");
	if (mstr->input == 1 && !valid_rules(*line))
		while (!valid_rules(*line))
		{
			printf("Please enter valid instruction: ");
			mstr->plus = get_next_line(mstr->read, line);
		}
	if (mstr->read == 0 && !valid_rules(*line))
		return (1);
	if (mstr->read != 0 && mstr->read != 1 && !valid_rules(*line))
	{
		printf("Next command in instructions file is invalid\n");
		return (1);
	}
	return (0);
}

int	valid_rules(char *line)
{
	if (ft_strcmp(line, "sa") != 0 && ft_strcmp(line, "sb") != 0 &&
		ft_strcmp(line, "rrr") != 0 && ft_strcmp(line, "pa") != 0 &&
		ft_strcmp(line, "rra") != 0 && ft_strcmp(line, "rrb") != 0 &&
		ft_strcmp(line, "rb") != 0 && ft_strcmp(line, "rr") != 0 &&
		ft_strcmp(line, "ss") != 0 && ft_strcmp(line, "ra") != 0 &&
		ft_strcmp(line, "pb") != 0 && line[0] != '\0')
		return (0);
	return (1);
}

int	pars_error(int argc)
{
	if (argc > 1)
		ft_putendl_fd("Error", 2);
	return (1);
}
