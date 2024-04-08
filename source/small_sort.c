/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:56:12 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 16:30:42 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_min_for_position(t_stack *lst)
{
	t_stack	*curr;
	t_stack	*min;

	if (lst == NULL)
		return (NULL);
	min = NULL;
	curr = lst;
	while (curr != NULL)
	{
		if (min == NULL || curr->index < min->index)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

int	get_position(t_stack *lst)
{
	t_stack	*head;
	t_stack	*min;
	int		position;
	int		i;

	position = 0;
	i = 0;
	min = get_min_for_position(lst);
	head = lst;
	while (head != NULL)
	{
		if (min->index == head->index)
			position = i;
		head = head->next;
		i++;
	}
	return (position);
}

void	sort_three(t_stack **lst)
{
	if ((*lst)->index > (*lst)->next->index
		&& (*lst)->index < (*lst)->next->next->index
		&& (*lst)->next->index < (*lst)->next->next->index)
		ft_sa(lst);
	else if ((*lst)->next->index < (*lst)->index
		&& (*lst)->next->index > (*lst)->next->next->index)
	{
		ft_sa(lst);
		ft_rra(lst);
	}
	else if ((*lst)->index > (*lst)->next->index
		&& (*lst)->next->index < (*lst)->next->next->index
		&& (*lst)->index > (*lst)->next->next->index)
		ft_ra(lst);
	else if ((*lst)->index < (*lst)->next->index
		&& (*lst)->index < (*lst)->next->next->index
		&& (*lst)->next->index > (*lst)->next->next->index)
	{
		ft_sa(lst);
		ft_ra(lst);
	}
	else if ((*lst)->index < (*lst)->next->index
		&& (*lst)->index > (*lst)->next->next->index
		&& (*lst)->next->index > (*lst)->next->next->index)
		ft_rra(lst);
}

void	sort_four(t_stack **lst, t_stack **stack)
{
	int	pos;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	pos = 0;
	pos = get_position(*lst);
	if (pos == 1)
		ft_ra(lst);
	else if (pos == 2)
	{
		ft_ra(lst);
		ft_ra(lst);
	}
	else if (pos == 3)
		ft_rra(lst);
	ft_pb(lst, stack);
	sort_three(lst);
	ft_pa(lst, stack);
}

void	sort_five(t_stack **lst, t_stack **stack)
{
	int	p;

	p = 0;
	p = get_position(*lst);
	if (p == 1)
		ft_sa(lst);
	if (p == 2)
	{
		ft_ra(lst);
		ft_ra(lst);
	}
	if (p == 3)
	{
		ft_rra(lst);
		ft_rra(lst);
	}
	if (p == 4)
		ft_rra(lst);
	ft_pb(lst, stack);
	sort_four(lst, stack);
	ft_pa(lst, stack);
}
