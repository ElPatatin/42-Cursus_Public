/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:43:59 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/liblist.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
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
