/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:46:54 by min-kim           #+#    #+#             */
/*   Updated: 2019/01/30 20:38:24 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*t;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && (s[start] == ' ' || s[start] == '\t' ||
				s[start] == '\n'))
		start++;
	while (s[start] && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (!(t = ft_strnew(end + 1)))
		return (NULL);
	return (ft_strsub(s, (unsigned int)start, (unsigned int)(end - start + 1)));
}
