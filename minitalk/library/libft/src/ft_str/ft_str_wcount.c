/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_wcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:48:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:52:28 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_str_wcount(char const *s, char c)
{
	size_t	i;
	int		nbr_w;

	i = 0;
	nbr_w = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] && s[i] == c)
			++i;
		while (s[i] && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				++nbr_w;
			++i;
		}
	}
	return (nbr_w);
}
