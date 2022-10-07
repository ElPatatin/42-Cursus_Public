/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:54:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 06:00:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_putnbr_fd(t_ll nbr, int fd)
{
	char	*str;

	str = "0123456789";
	if (nbr < 0)
	{
		if (write(fd, "-", sizeof(char)) != sizeof(char))
			return (-1);
		ft_absval(nbr);
	}
	if (nbr >= 10)
		if (ft_putnbr(nbr / 10) == -1)
			return (-1);
	if (write(fd, &str[nbr % 10], sizeof(char)) != sizeof(char))
		return (-1);
	return (0);
}
