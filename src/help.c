
#include "../push_swaplib.h"

void	add_next(t_str *new, t_str **anc)
{
	t_str *ptr;

	ptr = *anc;
	new->next = ptr->next;
	ptr->next = new;
}

void	add_node(t_str *new, t_str **anc)
{
	new->next = *anc;
	*anc = new;
}

t_str	*make_node(int value)
{
	t_str *new;

	new = (t_str*)malloc(sizeof(t_str));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	move_from_to(t_str **from, t_str **to)
{
	t_str *tmp;
	t_str *ptr;

	if (*from != NULL)
	{
		tmp = *from;
		ptr = *from;
		*from = ptr->next;
		tmp->next = *to;
		*to = tmp;
	}
}

void	move_s2_s1(t_str **a, t_str **b, t_help *mstr)
{
	move_from_to(&*b, &*a);
	if (mstr->pr == 1)
		printf("pa\n");
	mstr->sum += 1;
}
