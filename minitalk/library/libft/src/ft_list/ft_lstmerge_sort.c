/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:15:32 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:42:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	ft_lstsort_merge_insert(t_list **list, t_list *element,
				int (*cmp)())
{
	if (!*list || cmp(element->data, (*list)->data) <= 0)
	{
		element->next = *list;
		*list = element;
	}
	else
		ft_lstsort_merge_insert(&(*list)->next, element, cmp);
}

void	ft_lstmerge_sort(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	if (!begin_list2)
		return ;
	ft_lstmerge_sort(begin_list1, begin_list2->next, cmp);
	ft_lstsort_merge_insert(begin_list1, begin_list2, cmp);
}

// Esta función esta para revisar.
