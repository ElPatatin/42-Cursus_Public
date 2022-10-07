/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:51:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:50:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (TRUE);
	return (FALSE);
}

/*										*/
/*	Esta función revisa si el character que le pasamos esta dentro los	*/
/*	alfabetos de números o de letrás, tanto en las mayusculas como las	*/
/*	minúsculas, sobre los valores de la table ASCII. Si el parámetro	*/
/*	pasado esta fuera del rango la función devuelve un 0 o NULL.	  	*/
/*										*/
