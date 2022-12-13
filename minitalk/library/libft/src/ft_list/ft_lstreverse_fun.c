/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse_fun.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:16:42 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:42:50 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstreverse_fun(t_list *begin_list)
{
	void	*tmp;
	t_list	*aux1;
	t_list	*aux2;
	t_unt	i;
	t_unt	j;

	i = 0;
	j = ft_lstsize(begin_list) - 1;
	while (j > i)
	{
		aux1 = ft_lstat(begin_list, i);
		aux2 = ft_lstat(begin_list, j);
		tmp = ft_lstat(begin_list, i)->data;
		aux1->data = aux2->data;
		ft_lstat(begin_list, j)->data = tmp;
		++i;
		--j;
	}
}
