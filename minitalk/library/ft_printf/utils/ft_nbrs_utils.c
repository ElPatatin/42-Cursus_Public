/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:03:21 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/06/12 11:15:26 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*ft_setstring(char c)
{
	char	*str;

	if (c == 'd' || c == 'i' || c == 'u')
		return (str = BASE10);
	if (c == 'x')
		return (str = BASE16L);
	if (c == 'X')
		return (str = BASE16U);
	return (NULL);
}

static int	ft_nbrlen1(long nbr, int base, char c)
{
	int	len;

	len = 0;
	if (nbr < 0 && (c == 'u' || c == 'x' || c == 'X'))
		nbr = UINT_MAX + nbr + 1;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
			nbr /= base;
			len++;
	}
	return (len);
}

static int	ft_putnbr1(long nbr, int base, char c)
{
	char	*str;

	str = ft_setstring(c);
	if (nbr < 0)
	{
		if (c == 'd' || c == 'i')
		{
			if (write(STDOUT_FILENO, "-", sizeof(char)) != sizeof(char))
				return (ERR_NUM);
			nbr = -nbr;
		}
		else
			nbr = UINT_MAX + nbr + 1;
	}
	if (nbr >= base)
		if (ft_putnbr1(nbr / base, base, c) == ERR_NUM)
			return (ERR_NUM);
	if (write(STDOUT_FILENO, &str[nbr % base], 1) != 1)
		return (ERR_NUM);
	return (0);
}

int	ft_nbrbase(int n, int base, char c)
{
	ssize_t	bytes;

	bytes = ft_putnbr1((long)n, base, c);
	if (bytes == ERR_NUM)
		return (ERR_NUM);
	return (ft_nbrlen1((long)n, base, c));
}
