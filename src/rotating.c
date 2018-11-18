
#include "../swaplib.h"

void	rev_rotate(t_str **anc)
{
	t_str	*pre;
	t_str	*ptr;
	t_str	*last;

	ptr = *anc;
	if (ptr != NULL && ptr->next != NULL)
	{
		pre = ptr;
		while (pre->next->next != NULL)
			pre = pre->next;
		last = ptr;
		while (last->next != NULL)
			last = last->next;
		last->next = *anc;
		*anc = last;
		pre->next = NULL;
	}
}

void	rev_rotate_a(t_str **a, t_help *mstr)
{
	rev_rotate(&*a);
	if (mstr->print == 1)
		printf("rra\n");
	mstr->total += 1;
}

void	rev_rotate_b(t_str **b, t_help *mstr)
{
	rev_rotate(&*b);
	if (mstr->print == 1)
		printf("rrb\n");
	mstr->total += 1;
}

void	rotate_s1(t_str **a, t_help *mstr)
{
	rotate(&*a);
	mstr->total += 1;
	if (mstr->print == 1)
		printf("ra\n");
}

void	rotate(t_str **anc)
{
	t_str *ptr;
	t_str *tmp;

	ptr = *anc;
	if (ptr != NULL && ptr->next != NULL)
	{
		tmp = *anc;
		*anc = ptr->next;
		ptr = *anc;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
		tmp->next = NULL;
	}
}
