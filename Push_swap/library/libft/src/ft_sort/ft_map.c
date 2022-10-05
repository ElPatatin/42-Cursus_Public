/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:44:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:31:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
