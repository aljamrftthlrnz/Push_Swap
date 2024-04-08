/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:56:39 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 19:58:24 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	found_nonnumeric_char(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	found_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	found_duplicate(long num, int j, char **s)
{
	j++;
	while (s[j])
	{
		if (ft_atol(s[j]) == num)
			return (0);
		j++;
	}
	return (1);
}

int	found_arithmetic_operation(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '*' || s[i] == '/')
			return (0);
		if ((s[i] == '+' || s[i] == '-') && (!s[i + 1] || s[i + 1] == ' '))
			return (0);
		if (s[i + 1] == '-' || s[i + 1] == '+')
			return (0);
		if (s[0] == '0' && s[1] == '0')
			return (0);
		i++;
	}
	return (1);
}
