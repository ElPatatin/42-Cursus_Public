/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:02:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:50:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (TRUE);
	return (FALSE);
}

/*										*/
/*	Esta función revisa si el character que le pasamos esta entre los	*/
/*	primeros valores de la tabla ASCII. Si el parámetro pasado esta fuera	*/
/*	del rango designado de la función, el valor a devolver es 0 o NULL.	*/
/*										*/
