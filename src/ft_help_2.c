
#include "../swaplib.h"

int		ft_min(t_str *a)
{
	int		ret;
	int		count;
	t_str	*ptr;

	ret = a->value;
	count = 0;
	ptr = a;
	while (count < 3)
	{
		if (ptr->value < ret)
			ret = ptr->value;
		ptr = ptr->next;
		count += 1;
	}
	return (ret);
}

int		ft_max(t_str *a)
{
	int		ret;
	int		count;
	t_str	*ptr;

	ret = a->value;
	count = 0;
	ptr = a;
	while (count < 3)
	{
		if (ptr->value > ret)
			ret = ptr->value;
		ptr = ptr->next;
		count += 1;
	}
	return (ret);
}

int		ft_is_left(t_str *stack, int end, int pivot, int mem)
{
	t_str *ptr;

	ptr = stack;
	if (mem <= pivot && mem > end)
		return (1);
	while (ptr->value >= end)
	{
		if (ptr->value >= pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int		ft_is_left_a(t_str *stack, int end, int pivot)
{
	t_str *ptr;

	ptr = stack;
	while (ptr->value <= end)
	{
		if (ptr->value <= pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	vallet(t_str *node, int x, int base)
{
	t_str *ptr;

	ptr = node;
	while (ptr != NULL && ptr->value != x)
	{
		if (ptr->value < base)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
