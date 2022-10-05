/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:48:45 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:31:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strcapitalize(char *str)
{
	char	*start;

	start = str;
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
	++str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		if (!(*(str - 1) >= '0' && *(str - 1) <= '9')
			&& !(*(str - 1) >= 'A' && *(str - 1) <= 'Z')
			&& !(*(str - 1) >= 'a' && *(str - 1) <= 'z')
			&& *str >= 'a' && *str <= 'z')
			*str -= 32;
		++str;
	}
	return (start);
}
