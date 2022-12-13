/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:16:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:42:54 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstreverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*tmp;
	t_list	*pre;

	if (!begin_list)
		return ;
	current = *begin_list;
	pre = NULL;
	while (current)
	{
		tmp = current->next;
		current->next = pre;
		pre = current;
		current = tmp;
	}
	*begin_list = pre;
}
