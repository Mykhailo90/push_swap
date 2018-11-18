
#include "../swaplib.h"

static void	ft_before_a(t_help mstr, char const *line)
{
	if (mstr.highlight == 1 && (ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "pa") == 0 ||
			ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "rrr") == 0
			|| ft_strcmp(line, "rr") == 0))
		printf("[");
	if (mstr.highlight == 1 && (ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rr") == 0))
		printf("⇽ ");
	if (mstr.highlight == 1 && (ft_strcmp(line, "rra") == 0 ||
		ft_strcmp(line, "rrr") == 0))
		printf("⇾ ");
}

static void	ft_after_a(t_help mstr, char const *line)
{
	if (mstr.highlight == 1 && ft_strcmp(line, "pb") == 0)
		printf(" ↘ ");
	if (mstr.highlight == 1 && (ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rr") == 0))
		printf(" ⇽");
	if (mstr.highlight == 1 && (ft_strcmp(line, "rra") == 0 ||
		ft_strcmp(line, "rrr") == 0))
		printf(" ⇾");
	if (mstr.highlight == 1 && (ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "pa") == 0 ||
			ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "rrr") == 0
			|| ft_strcmp(line, "rr") == 0))
		printf("]");
	printf(": ");
}

static void	ft_before_b(t_help mstr, char const *line)
{
	if (mstr.highlight == 1 && (ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rrb") == 0 || ft_strcmp(line, "pa") == 0 ||
			ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "rrr") == 0
			|| ft_strcmp(line, "rr") == 0))
		printf("[");
	if (mstr.highlight == 1 && (ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rr") == 0))
		printf("⇽ ");
	if (mstr.highlight == 1 && (ft_strcmp(line, "rrb") == 0 ||
		ft_strcmp(line, "rrr") == 0))
		printf("⇾ ");
}

static void	ft_after_b(t_help mstr, char const *line)
{
	if (mstr.highlight == 1 && ft_strcmp(line, "pa") == 0)
		printf(" ↗ ");
	if (mstr.highlight == 1 && (ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rr") == 0))
		printf(" ⇽");
	if (mstr.highlight == 1 && (ft_strcmp(line, "rrb") == 0 ||
		ft_strcmp(line, "rrr") == 0))
		printf(" ⇾");
	if (mstr.highlight == 1 && (ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rrb") == 0 || ft_strcmp(line, "pa") == 0 ||
			ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "rrr") == 0
			|| ft_strcmp(line, "rr") == 0))
		printf("]");
	printf(": ");
}

void		print_separator(t_str *a, t_str *b, char const *l, t_help mstr)
{
	t_str 	*ptr;

	ptr = a;
	printf("\n");
	ft_before_a(mstr, l);
	printf("a");
	ft_after_a(mstr, l);
	print_a(ptr, a, mstr, l);
	printf("|\n");
	ptr = b;
	ft_before_b(mstr, l);
	printf("b");
	ft_after_b(mstr, l);
	print_b(ptr, b, mstr, l);
	printf("|\n\n");
}
