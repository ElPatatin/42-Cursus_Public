/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:02:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:28:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isascii(int c)
{
	if (!((c >= 0) && (c <= 127)))
		return (0);
	return (1);
}

/*										*/
/*	Esta función revisa si el character que le pasamos esta entre los	*/
/*	primeros valores de la tabla ASCII. Si el parámetro pasado esta fuera	*/
/*	del rango designado de la función, el valor a devolver es 0 o NULL.	*/
/*										*/
