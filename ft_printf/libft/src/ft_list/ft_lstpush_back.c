/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:15:56 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/07/18 17:15:58 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_list.h"

void	ft_lstpush_back(t_list **begin_list, void *data)
{
	t_list	*new_end;
	t_list	*current;

	new_end = ft_lstnew_elt(data);
	if (!begin_list)
	{
		*begin_list = new_end;
		return ;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = new_end;
}
