/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:00:02 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:56:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char
	*ft_itoa(int nbr)
{
	char	*res;
	int		len;

	len = ft_nbrlen(nbr);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
		res[0] = '-';
	else if (nbr == 0)
		res[0] = '0';
	while (nbr)
	{
		--len;
		res[len] = ft_absval(nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
