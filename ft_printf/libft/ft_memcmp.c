/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:38:54 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/13 11:35:36 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			i;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}

/*										*/
/*	La función memcmp localiza la primera ocurrencia de la diferencia	*/
/*	de dos string pasadas como parámetros por n bytes y devuelve esa	*/
/*	misma diferencia como resultado. Devolvera 0 o NULL si las dos ca-	*/
/*	denas pasadas son idénticas.						*/
/*										*/
