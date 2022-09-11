/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:43:54 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/liblist.h"

void	ft_lstsort_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*elt;

	current = *begin_list;
	elt = ft_lstnew_elt(data);
	if (!current)
	{
		*begin_list = elt;
		return ;
	}
	if ((*cmp)(elt->data, current->data) < 0)
	{
		elt->next = current;
		*begin_list = elt;
		return ;
	}
	while (current->next && (*cmp)(elt->data, current->next->data) > 0)
		current = current->next;
	elt->next = current->next;
	current->next = elt;
}
