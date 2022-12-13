/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:41:22 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:46:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	*ft_rrange(int start, int end)
{
	int	nbrcount;
	int	*ptr;
	int	i;
	int	flag;

	i = 0;
	nbrcount = 1 + ft_absval(end - start);
	ptr = (int *)malloc(sizeof(int) * nbrcount);
	if (start > end)
		flag = 1;
	else
		flag = -1;
	while (nbrcount > i)
	{
		ptr[i++] = end;
		end += flag;
	}
	return (ptr);
}
