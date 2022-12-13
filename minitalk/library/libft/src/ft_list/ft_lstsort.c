/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:43:03 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	int		swap;
	t_list	*current;

	swap = 1;
	current = *begin_list;
	while (swap == 1)
	{
		swap = 0;
		while (current && current->next)
		{
			if ((*cmp)(current->data, current->next->data) == 0)
			{
				ft_lstswap(current, current->next);
				swap = 1;
			}
			current = current->next;
		}
	}
}
