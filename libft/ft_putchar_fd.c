/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:14:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/17 15:24:03 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

/*										*/
/*	Esta función simplemente es una función putchar normal y corriente,	*/
/*	solo que su salida estandar ha sido cambiada a fd->file descriptor.	*/
/*	Un file descriptor es un identificador único para archivos u otros	*/
/*	recursos de entrada/salida; Tales como "pipes" o sockets de red.	*/
/*										*/
