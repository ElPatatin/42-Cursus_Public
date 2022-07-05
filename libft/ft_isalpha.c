/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:37:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/27 10:52:22 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
		return (1);
	return (0);
}

/*										*/
/*	Esta función revisa si el character que le pasamos esta dentro del      */
/*	alfabeto de letras, ya sean mayúsculas o miúsculas. Si el parámetro	*/
/*	pasado esta fuera del rango designado de la función, el valor a de-	*/
/*	volver es 0 o NULL.							*/
/*										*/
