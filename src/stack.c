/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:37:04 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/25 05:47:12 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

void				push(t_matrix_element **matrix_element_stack,
		t_matrix_element *new_element)
{
	if (matrix_element_stack)
	{
		if (new_element)
			new_element->next = *matrix_element_stack;
		*matrix_element_stack = new_element;
	}
}

t_matrix_element	*pop(t_matrix_element **matrix_element_stack)
{
	t_matrix_element	*top;

	top = NULL;
	if (matrix_element_stack && *matrix_element_stack)
	{
		top = *matrix_element_stack;
		*matrix_element_stack = (*matrix_element_stack)->next;
	}
	return (top);
}
