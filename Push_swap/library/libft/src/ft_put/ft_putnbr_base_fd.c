/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:54:14 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 06:00:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_putnbr_base_fd(t_ll nbr, int base, int fd)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr < 0)
	{
		if (base <= 10)
		{
			if (write(fd, "-", sizeof(char)) != sizeof(char))
				return (-1);
			ft_absval(nbr);
		}
		else
			nbr = UINT_MAX + nbr + 1;
	}
	if (nbr >= base)
		if (ft_putnbr_base_fd(nbr / base, base, fd) == -1)
			return (-1);
	if (write(fd, &str[nbr % base], sizeof(char)) != sizeof(char))
		return (-1);
	return (0);
}
