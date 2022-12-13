/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:08:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:10:47 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
