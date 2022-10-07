/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:11:27 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:57:57 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void
	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sptr;

	i = 0;
	sptr = (unsigned char *) s;
	while (i < n)
	{
		if (sptr[i] == (unsigned char) c)
			return (sptr + i);
		i++;
	}
	return (NULL);
}
