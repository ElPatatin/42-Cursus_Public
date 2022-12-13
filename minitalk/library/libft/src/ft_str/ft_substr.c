/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:52:20 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/08 18:37:51 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start > i)
		return (ft_strdup(""));
	if (start + len > i)
		len = i - start;
	size = len + 1;
	dst = (char *)malloc(sizeof(char) * size);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s + start, len);
	dst[len] = '\0';
	return (dst);
}
