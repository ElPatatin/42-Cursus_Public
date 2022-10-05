/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:07:14 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:28:44 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isprint(int c)
{
	if (!(c >= 32 && c <= 126))
		return (0);
	return (1);
}

/*										*/
/*	Esta función revisa si el character que le pasamos esta entre los	*/
/*	primeros valores de la tabla ASCII que sean imprimibles. Si el pará-	*/
/*	metro pasado esta fuera del rango designado de la función, el valor	*/
/*	a devolver es 0 o NULL.							*/
/*										*/
