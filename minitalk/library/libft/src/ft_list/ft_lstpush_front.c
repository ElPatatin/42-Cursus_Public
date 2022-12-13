/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:16:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 21:11:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstpush_front(t_list **begin_list, void *data)
{
	t_list	*new_elt;

	new_elt = ft_lstnew(data);
	new_elt->next = *begin_list;
	*begin_list = new_elt;
}
