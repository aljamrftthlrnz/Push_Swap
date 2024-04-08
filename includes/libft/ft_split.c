/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:44:43 by amirfatt          #+#    #+#             */
/*   Updated: 2024/01/30 16:33:54 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (s[i] == 0)
		return (0);
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_free(char **result, int word)
{
	int	f;

	f = 0;
	while (f < word)
	{
		free(result[f]);
		f++;
	}
	free(result);
}

static int	split_words(char **result, char const *s, char c, int word)
{
	int	start;
	int	end;

	end = 0;
	start = 0;
	while (s[end])
	{
		if (s[end] == c || s[end] == 0)
			start = end + 1;
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == 0))
		{
			result[word] = malloc(sizeof(char) * (end - start + 2));
			if (!result[word])
			{
				ft_free(result, word);
				return (0);
			}
			ft_strlcpy(result[word], (s + start), end - start + 2);
			word++;
		}
		end++;
	}
	result[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c, 0))
		return (NULL);
	return (result);
}
