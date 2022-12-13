/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:15:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:42:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstnew(void *data)
{
	struct s_list	*lst;

	lst = (t_list *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}
