/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:52:53 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	t_unt	src_s;
	t_unt	dest_s;
	t_unt	i;

	src_s = ft_strlen(src);
	dest_s = ft_strlen(dest);
	i = 0;
	if (dstsize == 0)
		return (src_s);
	if (dstsize <= dest_s)
		return (dstsize + src_s);
	while (dstsize && (--dstsize - dest_s) && src[i])
	{
		dest[dest_s + i] = src[i];
		i++;
	}
	dest[dest_s + i] = '\0';
	return (src_s + dest_s);
}
