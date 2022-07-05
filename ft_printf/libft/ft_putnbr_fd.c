/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:14:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/28 11:35:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Función putchar. Escribe un caracter con la salida fd.

static void	ft_write(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	int		j;
	char	c[10];

	i = n;
	j = 0;
	if (n == 0)
		ft_write('0', fd);
	if (i < 0)
	{
		ft_write('-', fd);
		i = -i;
	}
	while (i > 0)
	{
		c[j] = (i % 10) + '0';
		i = i / 10;
		j++;
	}
	while (--j >= 0)
		ft_write(c[j], fd);
}

/*										*/
/*	La función putnbr_fd recoge un número integer como parámetro y lo	*/
/*	imprime a la salida fd. Como la función hecha en la piscina, detec-	*/
/*	ta si la entrada es un integer positivo o negativo.			*/
/*										*/
