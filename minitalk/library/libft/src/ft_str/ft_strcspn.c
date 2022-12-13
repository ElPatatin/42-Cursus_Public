/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:25 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:52:44 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (reject[++j])
			if (s[i] == reject[j])
				return (i);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}

// Span a string
