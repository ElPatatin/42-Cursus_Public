/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:55:59 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/22 12:33:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && s != NULL)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return (NULL);
}

/*										*/
/*	la función strchr recorrera la string hasta que encuentre el momento	*/
/*	donde esta sea igual al parámetro C que le hemos pasado. Devolverá	*/
/*	el valor de ese momento en la string.					*/
/*										*/
