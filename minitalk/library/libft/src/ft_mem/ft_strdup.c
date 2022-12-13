/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:13:54 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:43:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}
