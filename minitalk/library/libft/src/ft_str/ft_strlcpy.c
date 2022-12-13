/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:50:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:52:57 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcpy(char *dst, const char *src, ssize_t dstsize)
{
	ssize_t	i;
	t_unt	len;

	i = -1;
	len = ft_strlen(src);
	if (!dstsize)
		return (0);
	while (src[++i] && i < (dstsize - 1))
		dst[i] = src[i];
	dst[i] = '\0';
	return (len);
}
