/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:01:06 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 19:51:38 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

/*ENTRY POINT*/
void				input_handle(int i, int f, char **num);
void				arg_checker(int argc, char **argv);
void				value_checker(t_stack **stack_a, int argc, char **argv);
void				values_into_stack(t_stack **stack_a, int i, int f,
						char **num);
void				sort(t_stack **stack_a, t_stack **stack_b);

/*HANDLE THE ARGUMENTS*/
int					found_space(char *s);
int					found_nonnumeric_char(char *s);
int					found_arithmetic_operation(char *s);
int					found_duplicate(long num, int j, char **s);

/*SORT TINY STACKS*/
void				sort_three(t_stack **lst);
void				sort_four(t_stack **lst, t_stack **stack);
void				sort_five(t_stack **lst, t_stack **stack);
int					get_position(t_stack *lst);
t_stack				*get_min_for_position(t_stack *lst);

/*SORT THE STACK*/
void				assign_position(t_stack *stack_a);
int					is_ascending(t_stack *stack);
void				radix_sort(t_stack **stack_a, t_stack **stack_b, int s);
int					count_bits(t_stack *lst);
t_stack				*get_max_for_radix(t_stack *lst);

/*PUSH OPERATION*/
void				push(t_stack **give, t_stack **receive);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);

/*SWAP OPERATION*/
void				swap(t_stack **lst);
void				ft_sa(t_stack **stack);
void				ft_sb(t_stack **stack);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

/*ROTATE OPERATION*/
void				rotate(t_stack **lst);
void				ft_ra(t_stack **lst);
void				ft_rb(t_stack **lst);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

/*REVERSE ROTATE OPERATION*/
void				reverse(t_stack **lst);
void				ft_rra(t_stack **stack);
void				ft_rrb(t_stack **stack);
void				ft_rrr(t_stack **lst, t_stack **stack);

/*HANDLE ERRORS AND FREES*/
void				error_input(char **str, int flag, char *msg);
void				free_and_exit(t_stack **stack_a, t_stack **stack_b,
						char **str);
void				free_stack(t_stack **lst);
void				free_string(char **str);

/*LINKED LIST UTILS*/
int					lst_size(t_stack *lst);
void				lst_addback(t_stack **stack, t_stack *new);
t_stack				*lst_last(t_stack *lst);
t_stack				*lst_new_node(int value, t_stack *new);
t_stack				*next_min(t_stack *node);

void				printList(t_stack **head);

#endif
