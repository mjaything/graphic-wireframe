/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:57:08 by min-kim           #+#    #+#             */
/*   Updated: 2019/01/30 20:12:45 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i])
				count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	wordlength(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	size_t	j;
	size_t	k;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (arr && wordcount(s, c))
	{
		i = 0;
		j = 0;
		while (s && j < wordcount(s, c) && s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			k = wordlength((char *)(s + i), c);
			if (!(arr[j] = ft_strnew(wordlength((char *)(s + i), c))))
				return (0);
			ft_strncpy(arr[j++], &s[i], k);
			while (s[i] && s[i] != c)
				i++;
		}
		arr[j] = NULL;
	}
	return (arr);
}
