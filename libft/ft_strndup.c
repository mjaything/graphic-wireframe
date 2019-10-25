/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:41:09 by min-kim           #+#    #+#             */
/*   Updated: 2019/09/17 11:20:00 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!(result = ft_strnew(n)))
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}
