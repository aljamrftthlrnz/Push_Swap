/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:55:20 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 19:44:35 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_input(char **str, int flag, char *msg)
{
	if (!flag)
		free_string(str);
	ft_putendl_fd(msg, 1);
	exit(1);
}

void	free_and_exit(t_stack **stack_a, t_stack **stack_b, char **str)
{
	if (str != NULL)
		free_string(str);
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
	exit(1);
}

void	free_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
	str = NULL;
}
