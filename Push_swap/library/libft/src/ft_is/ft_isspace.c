/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:11:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:51:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (TRUE);
	return (FALSE);
}

/*										*/
/*	Esta función revisa si el caracter que le pasamos esta dentro del	*/
/*	alfabeto de espacios, y/o es espacio. Devolvemos 1 si es así.		*/
/*										*/
