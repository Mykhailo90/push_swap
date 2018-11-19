
#include "../swaplib.h"

void	move_s1_s2(t_str **a, t_str **b, t_help *mstr)
{
	move_from_to(&*a, &*b);
	if (mstr->print == 1)
		printf("pb\n");
	mstr->total += 1;
}
