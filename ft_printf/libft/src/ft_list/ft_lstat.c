/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:13:59 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/07/18 17:14:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_list.h"

t_list	*ft_lstat(t_list *begin_list, t_unt nbr)
{
	t_list	*current;
	t_unt	idx;

	current = begin_list;
	idx = 0;
	while (idx < nbr)
	{
		if (!current)
			return (NULL);
		current = current->next;
		++idx;
	}
	return (current);
}
