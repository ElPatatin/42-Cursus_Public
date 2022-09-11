/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:11:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/06/11 16:18:57 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_ptrlen(t_unll nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static int	ft_ptr(t_unll nbr)
{
	ssize_t	bytes;

	if (nbr >= 16)
	{
		ft_ptr(nbr / 16);
		ft_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
		{
			bytes = ft_char(nbr + '0');
			if (bytes == ERR_NUM)
				return (ERR_NUM);
		}
		else
		{
			bytes = ft_char(nbr - 10 + 'a');
			if (bytes == ERR_NUM)
				return (ERR_NUM);
		}
	}
	return (0);
}

int	ft_vptr(t_unll nbr)
{
	ssize_t	bytes;

	if (write(STDOUT_FILENO, "0x", 2) != 2)
		return (-1);
	if (nbr == 0)
	{	
		if (write(STDOUT_FILENO, "0", sizeof(char)) != sizeof(char))
			return (ERR_NUM);
		return (sizeof(char) + 2);
	}
	else
	{
		bytes = ft_ptr(nbr);
		if (bytes == ERR_NUM)
			return (ERR_NUM);
	}
	return (ft_ptrlen(nbr) + 2);
}
