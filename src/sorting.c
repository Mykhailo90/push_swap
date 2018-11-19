
#include "../push_swaplib.h"

void	sorting(t_str **a, t_str **b, t_help *mstr)
{
	t_str *aptr;
	t_str *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr->next != NULL && aptr->value != get_min(aptr))
	{
		rotate_s1(a, mstr);
		aptr = *a;
	}
	while (bptr != NULL)
	{
		move_s2_s1(a, b, mstr);
		bptr = *b;
	}
}
