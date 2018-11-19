
#include "../swaplib.h"

void	swap_f_t(t_str **anc)
{
	t_str *ptr;
	t_str *tmp;

	ptr = *anc;
	if (ptr != NULL && ptr->next != NULL)
	{
		tmp = *anc;
		*anc = ptr->next;
		tmp->next = tmp->next->next;
		ptr = *anc;
		ptr->next = tmp;
	}
}

void	swap_both(t_str **a, t_str **b, t_help *mstr)
{
	swap_f_t(&*a);
	swap_f_t(&*b);
	mstr->sum += 1;
	if (mstr->pr == 1)
		printf("ss\n");
}

void	swap_s2(t_str **b, t_help *mstr)
{
	swap_f_t(&*b);
	mstr->sum += 1;
	if (mstr->pr == 1)
		printf("sb\n");
}

void	swap_s1(t_str **a, t_help *mstr)
{
	swap_f_t(&*a);
	mstr->sum += 1;
	if (mstr->pr == 1)
		printf("sa\n");
}
