/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:16:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:43:21 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/liblist.h"

void	ft_lstpush_front(t_list **begin_list, void *data)
{
	t_list	*new_elt;

	new_elt = ft_lstnew_elt(data);
	new_elt->next = *begin_list;
	*begin_list = new_elt;
}
