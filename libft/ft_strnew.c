/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:24:06 by min-kim           #+#    #+#             */
/*   Updated: 2019/01/15 14:26:18 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;
	size_t	i;

	i = 0;
	if (!(string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		string[i] = '\0';
		i++;
	}
	string[i] = '\0';
	return (string);
}
