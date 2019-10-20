/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:39:11 by min-kim           #+#    #+#             */
/*   Updated: 2019/01/28 19:36:42 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*s3;
	unsigned const char	*s4;

	s3 = s1;
	s4 = s2;
	i = 0;
	while (i < n)
	{
		if (s3[i] != s4[i])
			return ((int)(s3[i] - s4[i]));
		i++;
	}
	return (0);
}
