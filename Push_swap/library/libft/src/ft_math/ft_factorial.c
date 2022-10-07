/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:08:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:55:58 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_ll
	ft_factorial(t_ll nb)
{
	int	i;
	int	fact;

	if (nb < 0)
		return (0);
	i = 1;
	fact = 1;
	while (i <= nb)
	{
		fact = fact * i;
		i++;
	}
	return (fact);
}
