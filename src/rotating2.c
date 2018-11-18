
#include "../swaplib.h"

void	rotate_s2(t_str **b, t_help *mstr)
{
	rotate(&*b);
	mstr->total += 1;
	if (mstr->print == 1)
		printf("rb\n");
}

void	rotate_both(t_str **a, t_str **b, t_help *mstr)
{
	rotate(&*a);
	rotate(&*b);
	if (mstr->print == 1)
		printf("rr\n");
	mstr->total += 1;
}

void	rev_rotate_both(t_str **a, t_str **b, t_help *mstr)
{
	rev_rotate(&*a);
	rev_rotate(&*b);
	if (mstr->print == 1)
		printf("rrr\n");
	mstr->total += 1;
}

void	final_rotate(t_str **a, t_help *mstr)
{
	t_str *aptr;

	aptr = *a;
	if (rotating(aptr, get_min(aptr)) == 1)
		while (aptr->value != get_min(aptr))
		{
			rotate_s1(a, mstr);
			aptr = *a;
		}
	else
		while (aptr->value != get_min(aptr))
		{
			rev_rotate_a(a, mstr);
			aptr = *a;
		}
}
