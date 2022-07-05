/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:59:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/27 11:42:44 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;

	neg = 1;
	res = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * neg);
}

/*										*/
/*	Esta función convierte una string de numeros a un int si es posible.	*/
/*	Primero revisa si hay algún tipo de espacio a principio de la string	*/
/*	y si lo hay simplemente se los salta. A continuación revisa si hay	*/
/*	un signo antes del número. Si encuentra un signo y este es negativo,	*/
/*	cambiara el valor de una flag a negativo para cuando devolvamos el	*/
/*	valor entienda que ese número es negativo; Si en cambio el signo es	*/
/*	positivo, simplemente saltará el valor. Por último entramos en el bu-	*/
/*	cle que recorre la string hasta el final, pasando los números de una	*/
/*	string a un int y que siga hasta que se acabe la string o encuentre	*/
/*	algo distinto de un número. El valor a devolver es un int por la flag.	*/
/*										*/
