/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:54:57 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 09:55:03 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_bits(t_stack *lst)
{
	int	bit_count;
	int	tmp;

	tmp = lst->index;
	bit_count = 0;
	while (tmp != 0)
	{
		bit_count++;
		tmp >>= 1;
	}
	return (bit_count);
}

t_stack	*get_max_for_radix(t_stack *lst)
{
	t_stack	*curr;
	t_stack	*max;

	max = NULL;
	curr = lst;
	while (curr->next != NULL)
	{
		if (max == NULL || curr->index > max->index)
			max = curr;
		curr = curr->next;
	}
	return (max);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int s)
{
	t_stack	*max;
	t_stack	*head;
	int		loop;
	int		i;
	int		j;

	i = 0;
	max = get_max_for_radix(*stack_a);
	loop = count_bits(max);
	while (i < loop)
	{
		j = 0;
		while (j < s)
		{
			head = *stack_a;
			if (((head->index >> i) & 1))
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			j++;
		}
		while (lst_size(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}
