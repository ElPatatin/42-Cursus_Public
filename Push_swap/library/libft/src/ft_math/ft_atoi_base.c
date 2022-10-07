/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:59:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:55:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_atoi_base(const char *str, int base)
{
	int	res;
	int	neg;

	neg = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && (ft_isdigit(*str)))
	{
		res = res * base + (*str - 48);
		str++;
	}
	return (res * neg);
}
