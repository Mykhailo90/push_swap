
#include "../swaplib.h"

static int	get_bigs(t_str *b, int val)
{
	t_str   *ptr;
	int		ret;

	if (val > get_large(b))
		return (get_min(b));
	ptr = b;
	ret = get_large(b);
	while (ptr != NULL)
	{
		if (ptr->value < ret && ptr->value > val)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

void		flags_with_a(t_str **a, t_str **b, t_help *mstr)
{
	t_str   *bptr;
	t_str   *aptr;

	bptr = *b;
	aptr = *a;
	if (aptr != NULL &&
		rotating(aptr, get_bigs(aptr, bptr->value)) == 1)
		while (aptr->value != get_bigs(aptr, bptr->value))
		{
			rotate_s1(a, mstr);
			aptr = *a;
		}
	else
		while (aptr != NULL &&
			aptr->value != get_bigs(aptr, bptr->value))
		{
			rev_rotate_a(a, mstr);
			aptr = *a;
		}
	move_s2_s1(a, b, mstr);
}

void	flags_with_b(t_str **b, t_str **a, t_help *mstr)
{
	t_str *bptr;
	t_str *aptr;

	bptr = *b;
	aptr = *a;
	if (bptr != NULL &&
		rotating(bptr, get_max(bptr, aptr->value)) == 1)
		while (bptr->value != get_max(bptr, aptr->value))
		{
			rotate_s2(b, mstr);
			bptr = *b;
		}
	else
		while (bptr != NULL &&
			bptr->value != get_max(bptr, aptr->value))
		{
			rev_rotate_b(b, mstr);
			bptr = *b;
		}
	move_s1_s2(a, b, mstr);
}

int	rotating(t_str *anc, int to_find)
{
	t_str	*ptr;
	int		size;
	int		help;

	help = 1;
	size = get_size(anc);
	ptr = anc;
	while (ptr != NULL)
	{
		if (ptr->value == to_find)
			break ;
		help += 1;
		ptr = ptr->next;
	}
	if (size - help < size / 2)
		return (2);
	else
		return (1);
}
