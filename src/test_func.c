
#include "../swaplib.h"

int	test_sorted(t_str *anc)
{
	t_str   *ptr;
	int		min;

	ptr = anc;
	min = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	ptr = anc;
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value
			&& ptr->next->value != min)
			return (0);
		if (ptr->next == NULL &&
			ptr->value > anc->value && anc->value != min)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	test_swap(t_str *anc)
{
	int		big;
	int		little;
	int		last;
	t_str	*ptr;

	big = anc->value;
	little = anc->next->value;
	if (big > little && big < anc->next->next->value)
		return (1);
	ptr = anc;
	while (ptr->next != NULL)
		ptr = ptr->next;
	last = ptr->value;
	big = anc->value;
	little = anc->next->value;
	if ((big == get_large(anc) &&
		(anc->next->next->value == get_min(anc))) ||
		(big != get_large(anc) && (big < anc->next->next->value)))
		if (little > last || (little == get_min(anc)
			&& last == get_large(anc)))
			return (1);
	return (0);
}
