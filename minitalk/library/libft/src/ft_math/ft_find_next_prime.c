/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:09:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:10:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_find_next_prime(int nb)
{
	if (nb < 2)
		nb = 2;
	while (nb <= INT_MAX)
	{
		if (ft_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}
