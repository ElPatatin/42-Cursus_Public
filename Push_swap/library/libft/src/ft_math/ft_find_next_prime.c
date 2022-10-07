/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:09:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:56:01 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
