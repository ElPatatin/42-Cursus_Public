/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:59:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 21:01:29 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_atoi_base(const char *str, char *str_base)
{
	int	res;
	int	neg;
	int	base;

	neg = 1;
	res = 0;
	if (ft_ischrinstr(str_base)
		|| (ft_strlen(str_base) < 2 && ft_strlen(str_base) > 16))
		return (0);
	base = ft_strlen(str_base);
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
