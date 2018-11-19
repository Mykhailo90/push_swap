
#include "../push_swaplib.h"

static void	ft_loop_single(t_str **a, t_str **b, t_str *aptr, t_help *p)
{
	if (aptr->value <= p->base)
		move_s1_s2(a, b, p);
	else
		rotate_s1(a, p);
}

static void	ft_p_or_r_a(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;

	aptr = *a;
	while (aptr->value != mstr->mem)
	{
		ft_loop_single(a, b, aptr, mstr);
		aptr = *a;
	}
	ft_loop_single(a, b, aptr, mstr);
}

void		break1(t_str **a, t_str **b, t_help *mstr, t_str **p)
{
	t_str *aptr;

	aptr = *a;
	while (!test_sorted(*a))
	{
		mstr->base = get_base(*a, get_size(*a) / 2);
		mstr->mem = get_last_val(*a);
		ft_p_or_r_a(a, b, mstr);
		aptr = *a;
		add_node(make_node(get_min(*a)), p);
	}
	while (aptr->value != get_min(*a))
	{
		rotate_s1(a, mstr);
		aptr = *a;
	}
}
