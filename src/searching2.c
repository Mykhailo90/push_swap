
#include "../swaplib.h"

static t_str	*ft_search(t_str *ptr, t_str *anc, int *help)
{
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value
			&& !(ptr->value == get_large(anc)
				&& ptr->next->value == get_min(anc)))
			break ;
		if (ptr->next == NULL && ptr->value > anc->value
			&& !(ptr->value == get_large(anc)
				&& anc->value == get_min(anc)))
			break ;
		*help += 1;
		ptr = ptr->next;
	}
	return (ptr);
}

int				search_unsort(t_str *anc, int min, int max, int *mem)
{
	t_str 		*ptr;
	int			help;
	int			size;

	help = 1;
	size = 0;
	ptr = anc;
	min = ptr->value;
	max = get_large(anc);
	while (ptr != NULL)
	{
		size += 1;
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	ptr = anc;
	ptr = ft_search(ptr, anc, &help);
	*mem = ptr->value;
	if (size - help < size / 2)
		return (2);
	min = max;
	return (1);
}
