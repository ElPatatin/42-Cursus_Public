/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:14:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:42:11 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstforeach_if(t_list *begin_list, void (*f)(void *),
			void *data_ref, int (*cmp)())
{
	if (!begin_list || !data_ref)
		return ;
	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
