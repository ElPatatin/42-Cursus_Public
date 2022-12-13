/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_strs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:16:16 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:42:42 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstpush_strs(int size, char **strs)
{
	t_list	*new_strs;
	int		idx;

	new_strs = NULL;
	idx = 0;
	while (idx < size)
		ft_lstpush_front(&new_strs, strs[idx++]);
	return (new_strs);
}
