/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:55:32 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 19:44:49 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lst_size(t_stack *lst)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = lst;
	while (current != 0)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	lst_addback(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (stack)
	{
		if (*stack == NULL)
			*stack = new;
		else
		{
			current = lst_last(*(stack));
			current->next = new;
		}
		new = NULL;
	}
}

t_stack	*lst_last(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	if (lst == 0)
		return (0);
	while (current->next != 0)
	{
		current = current->next;
	}
	return (current);
}

t_stack	*lst_new_node(int value, t_stack *new)
{
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}
