
#include "../swaplib.h"

void	move_s1_s2(t_str **a, t_str **b, t_help *mstr)
{
	move_from_to(&*a, &*b);
	if (mstr->print == 1)
		printf("pb\n");
	mstr->total += 1;
}

static int	get_bigs(t_str *b, int val)
{
	t_str *ptr;
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