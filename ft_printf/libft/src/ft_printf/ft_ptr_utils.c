/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:42:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/07/18 17:42:06 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_ft_printf.h"

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

static int	ft_ptrmake(t_unll nbr)
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
			if (bytes == -1)
				return (-1);
		}
		else
		{
			bytes = ft_char(nbr - 10 + 'a');
			if (bytes == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_ptr(t_unll nbr)
{
	int		len;
	ssize_t	bytes;

	len = 0;
	if (write(STDOUT_FILENO, "0x", 2) != 2)
		return (-1);
	if (nbr == 0)
	{	
		if (write(STDOUT_FILENO, "0", sizeof(char)) != sizeof(char))
			return (-1);
		return (sizeof(char) + 2);
	}
	else
	{
		bytes = ft_ptrmake(nbr);
		if (bytes == -1)
			return (-1);
	}
	return (ft_ptrlen(nbr) + 2);
}
