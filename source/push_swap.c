/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:55:42 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 20:01:43 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	value_checker(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	char	**num;
	int		flag;

	flag = 0;
	if (argc == 2)
	{
		i = 0;
		num = ft_split(argv[1], ' ');
		if (!num)
			free_and_exit(stack_a, NULL, num);
	}
	else
	{
		i = 1;
		num = argv;
	}
	flag = i;
	values_into_stack(stack_a, i, flag, num);
}

void	values_into_stack(t_stack **stack_a, int i, int f, char **num)
{
	t_stack	*new;

	new = NULL;
	while (num[i])
	{
		new = lst_new_node(ft_atol(num[i]), new);
		if (new == NULL)
		{
			if (!f)
				free_and_exit(stack_a, NULL, num);
			else
				free_and_exit(stack_a, NULL, NULL);
		}
		lst_addback(stack_a, new);
		i++;
	}
	if (!f)
		free_string(num);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (size == 0)
		return ;
	if (!is_ascending(*stack_a) && stack_a != NULL)
	{
		if (lst_size(*stack_a) < 3)
			ft_sa(stack_a);
		else if (lst_size(*stack_a) < 4)
			sort_three(stack_a);
		else if (lst_size(*stack_a) < 5)
			sort_four(stack_a, stack_b);
		else if (lst_size(*stack_a) < 6)
			sort_five(stack_a, stack_b);
		else
			radix_sort(stack_a, stack_b, size);
	}
	else
		free_and_exit(stack_a, stack_b, NULL);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (-1);
	arg_checker(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	value_checker(&stack_a, argc, argv);
	assign_position(stack_a);
	sort(&stack_a, &stack_b);
	if (is_ascending(stack_a))
		free_and_exit(&stack_a, &stack_b, NULL);
	return (0);
}
