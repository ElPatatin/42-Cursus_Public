/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:51:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/07/09 18:11:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_ft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
		return (1);
	return (0);
}

/*										*/
/*	Esta función revisa si el character que le pasamos esta dentro los	*/
/*	alfabetos de números o de letrás, tanto en las mayusculas como las	*/
/*	minúsculas, sobre los valores de la table ASCII. Si el parámetro	*/
/*	pasado esta fuera del rango la función devuelve un 0 o NULL.	  	*/
/*										*/
