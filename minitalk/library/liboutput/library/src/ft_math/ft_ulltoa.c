/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:53:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/01 00:18:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_ulltoa(t_ull nbr, char *str)
{
	char	*res;
	t_unt	len;
	int		base;

	res = NULL;
	if (ft_ischrinstr(str) || (ft_strlen(str) < 2 && ft_strlen(str) > 16))
		return (NULL);
	base = ft_strlen(str);
	len = ft_unbrlen(nbr, base);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	else if (nbr == 0)
		res[0] = '0';
	while (nbr)
	{
		--len;
		res[len] = str[ft_absval(nbr % base)];
		nbr /= base;
	}
	return (res);
}
