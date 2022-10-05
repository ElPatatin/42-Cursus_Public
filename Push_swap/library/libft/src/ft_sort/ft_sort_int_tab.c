/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:44:25 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:31:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	t_unt	i;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		i = 1;
		swap = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				ft_swap(&tab[i - 1], &tab[i]);
				swap = 1;
			}
			++i;
		}
	}
}
