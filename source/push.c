/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:55:47 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 09:58:55 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **give, t_stack **receive)
{
	t_stack	*tmp;

	if (*give == NULL)
		return ;
	tmp = (*give)->next;
	(*give)->next = *receive;
	*receive = *give;
	*give = tmp;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
