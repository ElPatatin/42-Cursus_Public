/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:07:14 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:51:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	return (FALSE);
}

/*										*/
/*	Esta función revisa si el character que le pasamos esta entre los	*/
/*	primeros valores de la tabla ASCII que sean imprimibles. Si el pará-	*/
/*	metro pasado esta fuera del rango designado de la función, el valor	*/
/*	a devolver es 0 o NULL.							*/
/*										*/
