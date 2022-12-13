/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:53:08 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/01 00:08:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_unt	ft_unbrlen(t_ull nbr, int base)
{
	t_unt	len;

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
