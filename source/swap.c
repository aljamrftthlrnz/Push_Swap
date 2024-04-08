/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:56:32 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 09:56:33 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*second;

	if (*lst == NULL || lst_size(*lst) < 2)
		return ;
	first = *lst;
	second = (*lst)->next;
	tmp = second->next;
	second->next = first;
	first->next = tmp;
	*lst = second;
}

void	ft_sa(t_stack **stack)
{
	swap(stack);
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stack **stack)
{
	swap(stack);
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
