/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:54:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:48:51 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_putnbr_fd(t_ll nbr, int fd)
{
	char	*str;

	str = "0123456789";
	if (nbr < 0)
	{
		if (write(fd, "-", sizeof(char)) < 0)
			return (-1);
		ft_absval(nbr);
	}
	if (nbr >= 10)
		if (ft_putnbr(nbr / 10) == -1)
			return (-1);
	if (write(fd, &str[nbr % 10], sizeof(char)) < 0)
		return (-1);
	return (0);
}
