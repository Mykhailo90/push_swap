
#include "../push_swaplib.h"

void	move_s1_s2(t_str **a, t_str **b, t_help *mstr)
{
	move_from_to(&*a, &*b);
	if (mstr->pr == 1)
		printf("pb\n");
	mstr->sum += 1;
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

void	ft_apply(char *line, t_str **a, t_str **b, t_help *mstr)
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
