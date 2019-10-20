/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:07:40 by min-kim           #+#    #+#             */
/*   Updated: 2019/01/30 22:33:20 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*iter;

	if (!lst || !(iter = ft_lstnew(NULL, 0)))
		return (NULL);
	iter = f(lst);
	new = iter;
	while (lst->next)
	{
		lst = lst->next;
		iter->next = f(lst);
		iter = iter->next;
	}
	return (new);
}
