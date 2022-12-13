/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:16:28 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:42:46 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
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
