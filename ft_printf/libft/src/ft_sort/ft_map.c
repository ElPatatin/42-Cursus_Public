/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:44:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/07/18 17:44:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_ft.h"

int	*ft_map(int *tab, int lenght, int (*f)(int))
{
	int		*res;
	ssize_t	i;

	i = -1;
	res = (int *)malloc(sizeof(int) * lenght);
	if (!res)
		return (0);
	while (++i < lenght)
		res[i] = (*f)(tab[i]);
	return (res);
}
