/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:00:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/18 12:46:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	count;

	count = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{	
		while (count < len)
		{
			*((char *)(dst + count)) = *((char *)(src + count));
			count++;
		}
	}
	else
	{
		while (0 < len)
		{
			*((char *)((dst - 1) + len)) = *((char *)((src - 1) + len));
			len--;
		}
	}
	return (dst);
}

/*										*/
/*	La función memmove es muy parecida a la función memcpy, la diferen-	*/
/*	cía es que esta función intenta copiar el contenido de una string	*/
/*	a otra de forma segura. Esto lo hace durante n bytes.			*/
/*										*/
/*	Para entender un poco más que quiere decir de forma segura, vamos a	*/
/*	hechar un ojo a la función. Primero de todo tenemos una "guard close"	*/
/*	para revisar si algunos de los parametros que pasamos a la función	*/
/*	están vacios o no. Luego un if else revisando si la String destino	*/
/*	es más grande o no de la String source. Esto es muy imporante ya que	*/
/*	queremos copiar el contenido de las string de forma segura. Dentro	*/
/*	hay bucles diferentes; El primero copia desde el principio al final	*/
/*	de la String destino ya que siempre será ella quien llegue al final	*/
/*	primero. El otro bucle es al reves, empezamos a copiar desde el final	*/
/*	al principio hasta que la String source llegue al principio. Esto	*/
/*	es así porque la String source en este caso es más pequeña y acaba-	*/
/*	rá el bucle cuando acabe source. Ahora hemos conseguido mover el con-	*/
/*	tenido de forma segura.							*/
/*										*/
