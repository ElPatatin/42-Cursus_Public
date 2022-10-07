/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:13:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:58:45 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (!tab)
		return (0);
	while (i < (max - min))
	{
		tab[i] = min++;
		++i;
	}
	return (tab);
}
