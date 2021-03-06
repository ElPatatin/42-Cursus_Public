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
		return (str = "0123456789");
	if (c == 'x')
		return (str = "0123456789abcdef");
	if (c == 'X')
		return (str = "0123456789ABCDEF");
	return (NULL);
}

static int	ft_nbrlen(long nbr, int base, char c)
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

static int	ft_putnbr(long nbr, int base, char c)
{
	char	*str;

	str = ft_setstring(c);
	if (nbr < 0)
	{
		if (c == 'd' || c == 'i')
		{
			if (write(STDOUT_FILENO, "-", sizeof(char)) != sizeof(char))
				return (-1);
			nbr = -nbr;
		}
		else
			nbr = UINT_MAX + nbr + 1;
	}
	if (nbr >= base)
		if (ft_putnbr(nbr / base, base, c) == -1)
			return (-1);
	if (write(STDOUT_FILENO, &str[nbr % base], 1) != 1)
		return (-1);
	return (0);
}

int	ft_nbrbase(int n, int base, char c)
{
	ssize_t	bytes;

	bytes = ft_putnbr((long)n, base, c);
	if (bytes == -1)
		return (bytes);
	return (ft_nbrlen((long)n, base, c));
}
