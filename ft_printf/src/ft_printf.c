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

int	ft_printf(const char *fmt, ...)
{
	t_vars	vars;

	vars.idx = -1;
	vars.bytes = 0;
	va_start(vars.args, fmt);
	while (fmt[++vars.idx])
	{
		vars.c = fmt[vars.idx + 1];
		if (fmt[vars.idx] == '%')
		{
			vars.bytes += ft_check(&vars, fmt);
			if (vars.bytes == -1)
				return (-1);
			vars.idx++;
		}
		else
		{
			vars.bytes += ft_char(fmt[vars.idx]);
			if (vars.bytes == -1)
				return (-1);
		}
	}
	va_end(vars.args);
	return (vars.bytes);
}
