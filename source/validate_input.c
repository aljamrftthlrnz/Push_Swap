/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:56:47 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 19:57:45 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	arg_checker(int argc, char **argv)
{
	int		i;
	char	**num;
	int		flag;

	flag = 0;
	if (argc == 2)
	{
		i = 0;
		num = ft_split(argv[1], ' ');
		if (num == NULL || num[0] == 0)
			error_input(num, flag, "Error");
	}
	else
	{
		i = 1;
		num = argv;
	}
	flag = i;
	input_handle(i, flag, num);
}

void	input_handle(int i, int f, char **num)
{
	long	n;

	n = 0;
	while (num[i])
	{
		n = ft_atol(num[i]);
		if (!found_space(num[i]))
			error_input(num, f, "Error");
		else if (ft_strlen(num[i]) == 0)
			error_input(num, f, "Error");
		else if (!found_nonnumeric_char(num[i]))
			error_input(num, f, "Error");
		else if (!found_duplicate(n, i, num))
			error_input(num, f, "Error");
		else if (!found_arithmetic_operation(num[i]))
			error_input(num, f, "Error");
		else if (n > 2147483647 || n < -2147483648)
			error_input(num, f, "Error");
		i++;
	}
	if (!f)
		free_string(num);
}
