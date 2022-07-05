/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:40:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/20 12:38:46 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int	src_s;
	unsigned int	dest_s;
	unsigned int	i;

	src_s = ft_strlen(src);
	dest_s = ft_strlen(dest);
	i = 0;
	if (dstsize == 0)
		return (src_s);
	if (dstsize <= dest_s)
		return (dstsize + src_s);
	while (dstsize && (--dstsize - dest_s) && src[i])
	{
		dest[dest_s + i] = src[i];
		i++;
	}
	dest[dest_s + i] = '\0';
	return (src_s + dest_s);
}

/*										*/
/*	La función strlcat concatena 2 strings en una misma por len bytes.	*/
/*	Primero de nada revisamos que el tamaño de la concatenación que le	*/
/*	pasamos como parámetro no seá 0 y que tampoco sea más pequeño que	*/
/*	el tamaño de la string de destino. Hacemos el bucle de la concate-	*/
/*	ción y le damos a la nueva string el valor final de esta. La fun-	*/
/*	ción devolverá la suma de la longitud de las 2 string que le hemos	*/
/*	pasado como parámetro.							*/
/*	Entiendo que para que esta función sea funcional valga la redun-	*/
/*	dancía, el valor de la longitud que recibe la función debe ser la	*/
/*	la suma de la longitud de destino más cuantos bytes querémos con-	*/
/*	catenar para la nueva string.						*/
/*										*/
