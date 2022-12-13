/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:15:17 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:42:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	current = *begin_list1;
	if (!current)
		*begin_list1 = begin_list2;
	while (current->next)
		current = current->next;
	current->next = begin_list2;
}
