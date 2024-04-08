/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:56:04 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 09:59:04 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **lst)
{
	t_stack	*curr;
	t_stack	*old_last;
	t_stack	*new_top;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	curr = *lst;
	old_last = lst_last(*lst);
	new_top = (*lst)->next;
	old_last->next = curr;
	curr->next = NULL;
	*lst = new_top;
}

void	ft_ra(t_stack **lst)
{
	rotate(lst);
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stack **lst)
{
	rotate(lst);
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
