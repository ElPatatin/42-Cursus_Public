/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:35:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/23 14:22:48 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUnción que recorre un pointer de una string vacia y le asigna los números
// pasandolos de int a char.

static char	*ft_nbriteri(char *ptr, int nbr, size_t len)
{
	len--;
	while (nbr > 0)
	{
		ptr[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (ptr);
}

// Función que mide como es de grande un número

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// Función strcpy. La función strlcpy ya hecha no me servía para mi imple-
// mentación del itoa, ha si que he hecho un strcpy mas simple que sí sirve.

static char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

// Lógica de la función itoa

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;

	if (!n)
		return (ft_strdup("0"));
	len = ft_nbrlen(n);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(ptr, "-2147483648"));
	if (n < 0)
	{
		n = -n;
		ptr[0] = '-';
	}
	ptr = ft_nbriteri(ptr, n, len);
	ptr[len] = '\0';
	return (ptr);
}

/*										*/
/*	Esta implementación de una función itoa (integer to argument (String)	*/
/*	consiste en la inversa de una función atoi. Esta función recibe un	*/
/*	número integer como parametro y lo transforma a una string de carác-	*/
/*	teres. Aúnque antes de nada hay que alocar la memoría de la string	*/
/*	con los bytes suficientes de lo que queremos rellenar.			*/
/*										*/
