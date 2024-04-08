/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:56:20 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 17:43:43 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_ascending(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
		return (-1);
	current = stack;
	while (current && current->next != NULL)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*next_min(t_stack *node)
{
	t_stack	*head;
	t_stack	*min;

	min = NULL;
	head = node;
	while (head != NULL)
	{
		if ((head->index == -1) && (min == NULL || head->data < min->data))
			min = head;
		head = head->next;
	}
	return (min);
}

void	assign_position(t_stack *stack_a)
{
	int		i;
	t_stack	*next;

	i = 0;
	while (1)
	{
		next = next_min(stack_a);
		if (next == NULL)
			break ;
		next->index = i++;
	}
	if (is_ascending(stack_a))
		free_and_exit(&stack_a, NULL, NULL);
}
