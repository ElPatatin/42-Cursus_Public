/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:01:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/19 11:54:58 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (*(s + len) != (char) c)
	{
		--len;
		if (len == -1)
			return (0);
	}
	return ((char *)(s + len));
}

/*										*/
/*	La función de strrchr devuelve la última ocurrencia del parámetro	*/
/*	c dentro de la string s y devuelve ese valor.				*/
/*										*/
