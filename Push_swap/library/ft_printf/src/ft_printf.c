/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:32:26 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/06/13 10:19:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_check(va_list args, char c)
{
	ssize_t	bytes;

	bytes = 0;
	if (c == '%')
		bytes += ft_char('%');
	if (c == 'c')
		bytes += ft_char(va_arg(args, int));
	if (c == 's')
		bytes += ft_string(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		bytes += ft_nbrbase(va_arg(args, int), 10, c);
	if (c == 'u')
		bytes += ft_nbrbase(va_arg(args, int), 10, c);
	if (c == 'p')
		bytes += ft_vptr(va_arg(args, t_unll));
	if (c == 'x' || c == 'X')
		bytes += ft_nbrbase(va_arg(args, unsigned int), 16, c);
	return (bytes);
}

static int	ft_execute(const char *fmt, ssize_t i, ssize_t bytes, va_list args)
{
	char	c;

	while (fmt[++i])
	{
		c = fmt[i + 1];
		if (fmt[i] == '%')
		{
			bytes += ft_check(args, c);
			if (bytes == -1)
				return (-1);
			i++;
		}
		else
		{
			bytes += ft_char(fmt[i]);
			if (bytes == -1)
				return (-1);
		}
	}
	return (bytes);
}

int	ft_printf(const char *fmt, ...)
{
	ssize_t	i;
	ssize_t	bytes;
	va_list	args;

	i = -1;
	bytes = 0;
	va_start(args, fmt);
	bytes = ft_execute(fmt, i, bytes, args);
	va_end(args);
	return (bytes);
}
