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

static t_vars	ft_init_vars(const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	t_vars	vars;

	vars = ft_init_vars(fmt);
	va_start(vars.args, fmt);
	while (fmt[++vars.idx])
	{
		vars.c = fmt[vars.idx + 1];
		if (fmt[vars.idx] == '%')
		{
			vars.bytes += ft_check(&vars);
			if (vars.bytes == ERR_NUM)
				return (ERR_NUM);
			vars.idx++;
		}
		else
		{
			vars.bytes += ft_char(fmt[vars.idx]);
			if (vars.bytes == ERR_NUM)
				return (ERR_NUM);
		}
	}
	va_end(vars.args);
	return (vars.bytes);
}

static t_vars	ft_init_vars(const char *fmt)
{
	t_vars	vars;

	vars.idx = -1;
	vars.bytes = 0;
	vars.str = (char *)fmt;
	vars.fcount = 0;
	return (vars);
}
