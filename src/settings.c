
#include "../swaplib.h"

void	set_base(t_str *a, t_help *mstr)
{
	if (get_size(a) <= 20)
		mstr->base = get_base(a, get_size(a) / 2);
	else if (get_size(a) <= 50)
		mstr->base = get_base(a, get_size(a) / 2.5);
	else if (get_size(a) <= 100)
		mstr->base = get_base(a, get_size(a) / 3.5);
	else if (get_size(a) <= 250)
		mstr->base = get_base(a, get_size(a) / 4);
	else if (get_size(a) <= 300)
		mstr->base = get_base(a, get_size(a) / 5.5);
	else if (get_size(a) <= 350)
		mstr->base = get_base(a, get_size(a) / 6);
	else if (get_size(a) <= 400)
		mstr->base = get_base(a, get_size(a) / 6.5);
	else if (get_size(a) <= 450)
		mstr->base = get_base(a, get_size(a) / 7);
	else if (get_size(a) <= 500)
		mstr->base = get_base(a, get_size(a) / 7.5);
	else
		mstr->base = get_base(a, get_size(a) / 9);
}

int	get_base(t_str *a, int val)
{
	int		x;
	int		res;
	int		count;
	t_str	*ptr;

	count = 0;
	x = get_min(a);
	res = get_large(a);
	while (count < val)
	{
		res = get_large(a);
		ptr = a;
		while (ptr != NULL)
		{
			if (ptr->value < res && ptr->value > x)
				res = ptr->value;
			ptr = ptr->next;
		}
		x = res;
		count += 1;
	}
	return (res);
}

void	set_rev_base(t_str *a, t_help *mstr)
{
	if (get_size(a) <= 20)
		mstr->base = get_rev_base(a, get_size(a) / 2);
	else if (get_size(a) <= 50)
		mstr->base = get_rev_base(a, get_size(a) / 2.5);
	else if (get_size(a) <= 100)
		mstr->base = get_rev_base(a, get_size(a) / 3.5);
	else if (get_size(a) <= 250)
		mstr->base = get_rev_base(a, get_size(a) / 4);
	else if (get_size(a) <= 300)
		mstr->base = get_rev_base(a, get_size(a) / 5.5);
	else if (get_size(a) <= 350)
		mstr->base = get_rev_base(a, get_size(a) / 6);
	else if (get_size(a) <= 400)
		mstr->base = get_rev_base(a, get_size(a) / 6.5);
	else if (get_size(a) <= 450)
		mstr->base = get_rev_base(a, get_size(a) / 7);
	else if (get_size(a) <= 500)
		mstr->base = get_rev_base(a, get_size(a) / 7.5);
	else
		mstr->base = get_rev_base(a, get_size(a) / 9);
}

int	get_rev_base(t_str *a, int val)
{
	int		mem;
	int		ret;
	int		count;
	t_str	*ptr;

	count = 0;
	mem = get_large(a);
	ret = get_min(a);
	while (count < val)
	{
		ret = get_min(a);
		ptr = a;
		while (ptr != NULL)
		{
			if (ptr->value > ret && ptr->value < mem)
				ret = ptr->value;
			ptr = ptr->next;
		}
		mem = ret;
		count += 1;
	}
	return (ret);
}
