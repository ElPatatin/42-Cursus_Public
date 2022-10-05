/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:00:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:29:21 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_nbrlen_base(t_ll nbr, int base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr <= 0)
		len++;
	while (nbr)
	{
			nbr /= base;
			len++;
	}
	return (len);
}
