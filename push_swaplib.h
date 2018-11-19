
#ifndef PUSH_SWAPLIB_H
# define PUSH_SWAPLIB_H

# include "./libft/libft.h"

typedef struct		s_str
{
	int				help;
	struct s_str	*next;
	int				rev;
	int				value;
}					t_str;

typedef struct		s_help
{
	int				ac;
	int				base;
	int				input;
	int				hl;
	int				mem;
	int				not;
	int				out;
	int				plus;
	int				pr;
	int				read;
	int				res;
	int				sum;
	int				visual;
}					t_help;

void				add_next(t_str *new, t_str **anc);
void				add_node(t_str *new, t_str **anc);
void				break1(t_str **a, t_str **b, t_help *mstr,
								t_str **base);
void				break_s2(t_str **a, t_str **b, t_help *mstr,
								t_str **base);
void				break_s1(t_str **a, t_str **b, t_help *mstr,
								t_str **base);
int					build_st(t_str **a, t_help *mstr, char **argv, int argc);
void				config(char **argv, int argc, t_help *mstr);
void				del_nodes(t_str **anc);
void				fast_sor(t_str **a, t_str **b, t_help *mstr);
int					free_arr(char **nums, int res);
void				final_rotate(t_str **a, t_help *mstr);
void				free_list(t_str *a, t_str *b);
void				ft_apply(char *line, t_str **a, t_str **b, t_help *mstr);
void				flags_with_a(t_str **a, t_str **b, t_help *mstr);
void				flags_with_b(t_str **b, t_str **a, t_help *mstr);
int					get_rev_base(t_str *a, int val);
int					get_base(t_str *a, int val);
int					get_max(t_str *b, int val);
int					get_size(t_str *a);
int					get_last_val(t_str *anc);
int					get_min(t_str *anc);
int					get_large(t_str *anc);
int					get_bigs(t_str *b, int val);
int					input_validation(char **nums, t_help *mstr);
void				initialize(t_help *mstr, t_str **a, t_str **b, int *fd);
int					left_check(t_str *stack, int end, int base, int mem);
int					left_s1(t_str *stack, int end, int base);
t_str				*make_node(int value);
int					make_new_base(t_str *a, int tx);
int					min_s(t_str *a);
int					max_s(t_str *a);
void				move_s1_s2(t_str **a, t_str **b, t_help *mstr);
void				move_s2_s1(t_str **a, t_str **b, t_help *mstr);
void				move_from_to(t_str **from, t_str **to);
int					next_search(t_str *b, int base);
int					next_val(t_str *node, int mem, int base);
void				print_header(int *fd, t_str *a);
int					pars_inst(t_help *mstr, char **line);
int					print_result(t_help mstr, int fd, t_str *a, t_str *b);
int					pars_error(int argc);
void				print_s1(t_str *ptr, t_str *a, t_help mstr,
								char const *line);
void				print_s2(t_str *ptr, t_str *b, t_help mstr,
								char const *line);
void				print_separator(t_str *a, t_str *b, char const *line,
								t_help mstr);
void				rev_rotate(t_str **anc);
void				rotate(t_str **anc);
void				rotate_s1(t_str **a, t_help *mstr);
void				rotate_s2(t_str **b, t_help *mstr);
int					rotating(t_str *anc, int to_find);
void				rotate_both(t_str **a, t_str **b, t_help *mstr);
void				rev_rotate_a(t_str **a, t_help *mstr);
void				rev_rotate_b(t_str **b, t_help *mstr);
void				rev_rotate_both(t_str **a, t_str **b,
								t_help *mstr);
void				swap_s1(t_str **a, t_help *mstr);
void				swap_s2(t_str **b, t_help *mstr);
void				swap_both(t_str **a, t_str **b, t_help *mstr);
void				sort_q(t_str **a, t_str **b, t_help *mstr);
void				swap_f_t(t_str **anc);
void				swapins(t_str **a, t_str **b, t_help *mstr);
void				set_base(t_str *a, t_help *mstr);
void				stack_visual(t_help mstr, char *line, t_str *a,
								t_str *b);
void				start_print(t_help *mstr, int *fd, t_str *a, t_str *b);
void				sorting(t_str **a, t_str **b, t_help *mstr);
int					search_unsort(t_str *anc, int min,
								int max, int *mem);
int					search_size(t_str *b, int base);
int					search_s1_size(t_str *a, int base);
int					search_next_s1(t_str *a, int base);
void				swap3(t_str **a, t_str **b, t_help *mstr);
void				rev_sort_q(t_str **b, t_str **a, t_help *mstr);
void				rev_s2_d(t_str **a, t_str **b, t_help *mstr);
void				set_rev_base(t_str *a, t_help *mstr);
int					test_swap(t_str *anc);
int					test_sorted(t_str *anc);
int					vallet(t_str *node, int mem, int base);
int					valid_rules(char *line);
int					unique_check(t_str *a);

#endif
