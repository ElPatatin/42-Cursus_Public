/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:13:29 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:46:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*t;

	t = (unsigned char *) b;
	while (len-- > 0)
		*t++ = c;
	return (b);
}
