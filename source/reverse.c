/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:55:56 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 09:57:36 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse(t_stack **lst)
{
	t_stack	*new_top;
	t_stack	*second_last;
	t_stack	*current;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	new_top = lst_last(*lst);
	second_last = NULL;
	current = *lst;
	while (current->next != NULL)
	{
		second_last = current;
		current = current->next;
	}
	second_last->next = NULL;
	current->next = *lst;
	*lst = current;
}

void	ft_rra(t_stack **stack)
{
	reverse(stack);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stack **stack)
{
	reverse(stack);
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_stack **lst, t_stack **stack)
{
	reverse(lst);
	reverse(stack);
	ft_putendl_fd("rrr", 1);
}
