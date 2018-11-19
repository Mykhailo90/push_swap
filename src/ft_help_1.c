
#include "../push_swaplib.h"

int	search_size(t_str *b, int base)
{
	int		ret;
	t_str	*ptr;

	ret = 0;
	ptr = b;
	while (ptr->next && ptr->value >= base)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int	search_s1_size(t_str *a, int base)
{
	int		ret;
	t_str	*ptr;

	ret = 0;
	ptr = a;
	while (ptr->next && ptr->value <= base)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int	next_search(t_str *b, int base)
{
	t_str *ptr;

	ptr = b;
	while (ptr->next && ptr->value >= base)
		ptr = ptr->next;
	return (ptr->value);
}

int	search_next_s1(t_str *a, int base)
{
	t_str *ptr;

	ptr = a;
	while (ptr->next && ptr->value < base)
		ptr = ptr->next;
	return (ptr->value);
}

int	next_val(t_str *node, int x, int base)
{
	t_str *ptr;

	ptr = node;
	while (ptr->value != x)
	{
		if (ptr->value < base)
			break ;
		ptr = ptr->next;
	}
	return (ptr->value);
}
