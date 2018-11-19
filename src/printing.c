
#include "../push_swaplib.h"

void	start_print(t_help *mstr, int *fd, t_str *a, t_str *b)
{
	mstr->plus = 1;
	if (mstr->input == 1)
		mstr->read = 1;
	if (mstr->out == 1)
		print_header(fd, a);
	if (mstr->pr == 0 && mstr->visual == 1 && mstr->plus != 0)
	{
		printf("[START]\n ↓@↓@↓@↓@↓@↓@↓@↓@↓");
		print_separator(a, b, "NULL", *mstr);
	}
}

void	print_header(int *fd, t_str *a)
{
	*fd = creat("log.txt", S_IRUSR | S_IWUSR);
	ft_putendl_fd("________________________________________________", *fd);
	ft_putendl_fd("Instructions memo:                              |", *fd);
	ft_putendl_fd("sa - swap values 1 and values 2 in stack 'A'    |", *fd);
	ft_putendl_fd("sb - swap values 1 and values 2 in stack 'B'    |", *fd);
	ft_putendl_fd("ss - swap values 1 and values 2 in both stacks  |", *fd);
	ft_putendl_fd("ra - rotate stack 'A'                           |", *fd);
	ft_putendl_fd("rb - rotate stack 'B'                           |", *fd);
	ft_putendl_fd("rr - rotate both                                |", *fd);
	ft_putendl_fd("rra - reverse rotate 'A'                        |", *fd);
	ft_putendl_fd("rrb - reverse rotate 'B'                        |", *fd);
	ft_putendl_fd("rrr - reverse rotate both                       |", *fd);
	ft_putendl_fd("pa - add top val from stack 'B' to 'A'          |", *fd);
	ft_putendl_fd("pb - add top val form stack 'A' to 'B'          |", *fd);
	ft_putendl_fd("________________________________________________|", *fd);
	ft_putendl_fd("\n_____________________________\nYour values are:", *fd);
	while (a != NULL)
	{
		ft_putnbr_fd(a->value, *fd);
		ft_putchar_fd(' ', *fd);
		a = a->next;
	}
	ft_putendl_fd("\n", *fd);
	ft_putendl_fd("Sorting instructions:", *fd);
	ft_putendl_fd("________", *fd);
}

static void	print_concl(t_str *a, int fd, t_help mstr)
{
	if (test_sorted(a) && a->value == get_min(a))
	{
		if (mstr.out == 1)
			ft_putendl_fd("Values sorted success", fd);
		printf("OK\n");
	}
	else
	{
		if (mstr.out == 1)
			ft_putendl_fd("Values not sorted", fd);
		printf("KO\n");
	}
}

int			print_result(t_help mstr, int fd, t_str *a, t_str *b)
{
	if (mstr.out == 1)
		ft_putendl_fd("____________", fd);
	if (mstr.res == 1)
	{
		printf("Count operations: %d\n", mstr.sum);
		printf("___________________________________________\n");
		ft_putstr_fd("Count operations: ", fd);
		ft_putnbr_fd(mstr.sum, fd);
		ft_putchar_fd('\n', fd);
		ft_putendl_fd("__________________________________________", fd);
	}
	print_concl(a, fd, mstr);
	close(fd);
	free_list(a, b);
	return (0);
}

void	print_s1(t_str *ptr, t_str *a, t_help mstr, char const *line)
{
	while (ptr != NULL)
	{
		if (mstr.hl == 1 && ((ft_strcmp(line, "sa") == 0 &&
			(ptr == a || ptr == a->next)) ||
			(ft_strcmp(line, "pa") == 0 && ptr == a)))
			printf("[");
		printf("%d", ptr->value);
		if (mstr.hl == 1 && ((ft_strcmp(line, "sa") == 0 &&
			(ptr == a || ptr == a->next)) ||
			(ft_strcmp(line, "pa") == 0 && ptr == a)))
			printf("]");
		if (mstr.hl == 1 && ft_strcmp(line, "sa") == 0 &&
			ptr == a)
			printf(" ⇔ ");
		else
		{
			if (ptr->next != NULL)
				printf(" ⁀ ");
		}
		ptr = ptr->next;
	}
}
