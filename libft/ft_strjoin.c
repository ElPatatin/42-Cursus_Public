/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:17:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/13 17:06:45 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*ptr;
	size_t	i;

	i = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * i + 1);
	if (!(dst && s1 && s2))
		return (NULL);
	ptr = dst;
	while (*s1 != '\0')
		*dst++ = *s1++;
	while (*s2 != '\0')
		*dst++ = *s2++;
	*dst = '\0';
	return (ptr);
}

/*										*/
/*	La función strjoin une 2 strings en 1 sola. Alocamos la memotia de	*/
/*	la suma de las longitudes de las 2 strings y revisamos que ningún	*/
/*	parámetro que le hayamos pasado a la función este vació o que la 	*/
/*	alocación en sí haya fallado. Una vez hecho esto empezámos con la	*/
/*	unión de las 2 strings y le damos el valor final a la string final.	*/
/*	El valor devuelto es un puntero a esa string final.			*/
/*										*/
