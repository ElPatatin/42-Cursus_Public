/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:05:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/01 00:07:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ll	ft_nbrlen(t_ll nbr, int base)
{
	t_ll	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
