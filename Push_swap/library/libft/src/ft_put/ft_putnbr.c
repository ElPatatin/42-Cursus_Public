/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:54:03 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 06:00:16 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_putnbr(t_ll nbr)
{
	char	*str;

	str = "0123456789";
	if (nbr < 0)
	{
		if (write(STDOUT_FILENO, "-", sizeof(char)) != sizeof(char))
			return (-1);
		ft_absval(nbr);
	}
	if (nbr >= 10)
		if (ft_putnbr(nbr / 10) == -1)
			return (-1);
	if (write(STDOUT_FILENO, &str[nbr % 10], sizeof(char)) != sizeof(char))
		return (-1);
	return (0);
}
