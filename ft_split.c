/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:27:03 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/25 19:37:23 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int		i;
	int		word;
	int		count;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			word = 0;
		else if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*makeword(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	word[i] = 0;
	i--;
	while (i >= 0)
	{
		word[i] = s[i];
		i--;
	}
	return (word);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		word;
	int		count;
	int		i;

	if (!(split = (char **)malloc((countwords(s, c) + 1) * sizeof(char *))))
		return (NULL);
	word = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			word = 0;
		else if (s[i] != c && word == 0)
		{
			word = 1;
			if (!(split[count] = makeword(&s[i], c)))
				return (NULL);
			count++;
		}
		i++;
	}
	split[count] = 0;
	return (split);
}
