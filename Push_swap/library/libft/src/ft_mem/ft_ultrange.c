/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:14:20 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:59:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_ultrange(int **range, int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	if (min >= max || !range)
		return (0);
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (!tab)
		return (-1);
	while (i < (max - min))
	{
		tab[i] = min++;
		++i;
	}
	*range = tab;
	return (i);
}
