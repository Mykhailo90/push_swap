
#include "../swaplib.h"

void	print_b(t_str *ptr, t_str *b, t_help mstr, char const *line)
{
	while (ptr != NULL)
	{
		if (mstr.highlight == 1 && ((ft_strcmp(line, "sb") == 0 &&
			(ptr == b || ptr == b->next)) ||
			(ft_strcmp(line, "pb") == 0 && ptr == b)))
			printf("[");
		printf("%d", ptr->value);
		if (mstr.highlight == 1 && ((ft_strcmp(line, "sb") == 0 &&
			(ptr == b || ptr == b->next)) ||
			(ft_strcmp(line, "pb") == 0 && ptr == b)))
			printf("]");
		if (mstr.highlight == 1 && ft_strcmp(line, "sb") == 0 &&
			ptr == b)
			printf(" ⇔ ");
		else
		{
			if (ptr->next != NULL)
				printf(" ‿ ");
		}
		ptr = ptr->next;
	}
}

void	stack_visual(t_help mstr, char *line, t_str *a, t_str *b)
{
	if (mstr.print == 0 && mstr.visual == 1 && mstr.add != 0)
	{
		printf("[%s]\n", line);
		if (ft_strlen(line) == 2)
			printf(" ↓@↓");
		else
			printf(" ↓@↓@↓");
		print_separator(a, b, line, mstr);
	}
}