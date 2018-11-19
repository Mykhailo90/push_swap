/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:17:43 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/20 13:17:44 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPLIB_H
# define SWAPLIB_H

# include "./libft/libft.h"

typedef struct		s_str
{
	int				value;
	int				help;
	struct s_str	*next;
}					t_str;

typedef struct		s_help
{
	int				total;
	int				pivot;
	int				mem;
	int				add;
	int				print;
	int				visual;
	int				output;
	int				result;
	int				highlight;
	int				read;
	int				input;
	int				no;
	int				ac;
}					t_help;

int					free_arr(char **nums, int res);
void				config(char **argv, int argc, t_help *mstr);
int					pars_inst(t_help *mstr, char **line);
void				start_print(t_help *mstr, int *fd, t_str *a, t_str *b);
int					valid_rules(char *line);
void				stack_visual(t_help mstr, char *line, t_str *a,
								t_str *b);
void				print_header(int *fd, t_str *a);
int					print_result(t_help mstr, int fd, t_str *a, t_str *b);
int					pars_error(int argc);
int					input_validation(char **nums, t_help *mstr);
void				set_base(t_str *a, t_help *mstr);
void				flags_with_a(t_str **a, t_str **b, t_help *mstr);
void				flags_with_b(t_str **b, t_str **a, t_help *mstr);
void				sorting(t_str **a, t_str **b, t_help *mstr);
int					next_val(t_str *node, int mem, int pivot);
int					vallet(t_str *node, int mem, int pivot);
int					get_base(t_str *a, int val);
int					get_max(t_str *b, int val);
void				print_a(t_str *ptr, t_str *a, t_help mstr,
								char const *line);
void				print_b(t_str *ptr, t_str *b, t_help mstr,
								char const *line);
void				print_separator(t_str *a, t_str *b, char const *line,
								t_help mstr);
int					get_size(t_str *a);
int					get_last_val(t_str *anc);
int					get_min(t_str *anc);
int					get_large(t_str *anc);
int					test_swap(t_str *anc);
int					search_unsort(t_str *anc, int min,
								int max, int *mem);
int					test_sorted(t_str *anc);
int					rotating(t_str *anc, int to_find);
void				add_next(t_str *new, t_str **anc);
void				add_node(t_str *new, t_str **anc);
t_str				*make_node(int value);
void				move_from_to(t_str **from, t_str **to);
void				rev_rotate(t_str **anc);
void				rotate(t_str **anc);
void				swap_f_t(t_str **anc);
void				move_s1_s2(t_str **a, t_str **b, t_help *mstr);
void				move_s2_s1(t_str **a, t_str **b, t_help *mstr);
void				rotate_s1(t_str **a, t_help *mstr);
void				rotate_s2(t_str **b, t_help *mstr);
void				rotate_both(t_str **a, t_str **b, t_help *mstr);
void				rev_rotate_a(t_str **a, t_help *mstr);
void				rev_rotate_b(t_str **b, t_help *mstr);
void				rev_rotate_both(t_str **a, t_str **b,
								t_help *mstr);
void				swap_s1(t_str **a, t_help *mstr);
void				swap_s2(t_str **b, t_help *mstr);
void				swap_both(t_str **a, t_str **b, t_help *mstr);
void				ft_quick_sort(t_str **a, t_str **b, t_help *mstr);
void				ft_first_break(t_str **a, t_str **b, t_help *mstr,
								t_str **pivots);
void				ft_break_b(t_str **a, t_str **b, t_help *mstr,
								t_str **pivots);
void				ft_break_a(t_str **a, t_str **b, t_help *mstr,
								t_str **pivots);
void				ft_fast_af_boi(t_str **a, t_str **b, t_help *mstr);
void				ft_insert_swap(t_str **a, t_str **b, t_help *mstr);
void				final_rotate(t_str **a, t_help *mstr);
void				ft_del_node(t_str **anc);
void				free_list(t_str *a, t_str *b);
int					make_new_base(t_str *a, int tx);
int					ft_find_size(t_str *b, int pivot);
int					ft_find_size_a(t_str *a, int pivot);
int					ft_find_next(t_str *b, int pivot);
int					ft_find_next_a(t_str *a, int pivot);
int					ft_min(t_str *a);
int					ft_max(t_str *a);
int					ft_is_left(t_str *stack, int end, int pivot, int mem);
int					ft_is_left_a(t_str *stack, int end, int pivot);
void				ft_swap_three(t_str **a, t_str **b, t_help *mstr);
void				ft_rev_quick_sort(t_str **b, t_str **a, t_help *mstr);
void				ft_rev_deal_with_b(t_str **a, t_str **b, t_help *mstr);
int					get_bigs(t_str *b, int val);
void				set_rev_base(t_str *a, t_help *mstr);
int					get_rev_base(t_str *a, int val);
#endif
