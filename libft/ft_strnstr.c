/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:29:42 by min-kim           #+#    #+#             */
/*   Updated: 2019/01/29 16:41:06 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i + ft_strlen(needle) <= len)
	{
		if ((ft_strncmp(&haystack[i], needle, ft_strlen(needle))) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
