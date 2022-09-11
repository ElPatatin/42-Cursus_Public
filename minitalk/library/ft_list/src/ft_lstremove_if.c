/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:16:28 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:43:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/liblist.h"

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*tmp;
	t_list	*pre;

	pre = NULL;
	current = *begin_list;
	while (current)
	{
		while (current && (*cmp)(current->data, data_ref) == 0)
		{
			if (pre)
				pre->next = current->next;
			else
				*begin_list = current->next;
			(*free_fct)(current->data);
			tmp = current;
			current = current->next;
			free(tmp);
		}
		if (current)
		{
			pre = current;
			current = current->next;
		}
	}
}
