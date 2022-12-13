/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:09:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/05 11:24:18 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char
	*ft_strdup(const char *s1)
{
	char	*dst;

	if (!s1)
		return (ft_strdup("(null)"));
	dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}
