/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:40:16 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:56:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_unt
	ft_lcm(t_unt a, t_unt b)
{
	t_unt	tmp;

	if (!a || !b)
		return (0);
	if (a > b)
		tmp = a;
	else
		tmp = b;
	while (1)
	{
		if ((tmp % a) == 0 && (tmp % b) == 0)
			return (tmp);
		++tmp;
	}
}
