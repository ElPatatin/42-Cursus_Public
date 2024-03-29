/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_elt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:15:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/07/18 17:15:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_list.h"

t_list	*ft_lstnew_elt(void *data)
{
	t_list	*new_elt;

	new_elt = (t_list *)malloc(sizeof(t_list));
	if (!new_elt)
		return (NULL);
	new_elt->data = data;
	new_elt->next = NULL;
	return (new_elt);
}
