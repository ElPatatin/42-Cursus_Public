/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:06:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/27 10:52:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_ft.h"

int	ft_isdigit(int c)
{
	if (!((c >= '0') && (c <= '9')))
		return (0);
	return (1);
}

/*										*/
/*	Esta función revisa si el carácter que le pasamos esta dentro del	*/
/*	alfabeto de números. Si el parámetro pasado esta fuera del rango de-	*/
/*	signado de la función, el valor a devolver es 0 o NULL.			*/
/*										*/
