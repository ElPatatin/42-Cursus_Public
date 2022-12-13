/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:36:11 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 21:28:39 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_printf(const char *fmt, ...)
{
	t_vars	vars;
	t_flags	flags;

	vars = init_vars(fmt);
	va_start(vars.args, fmt);
	va_copy(vars.copy, vars.args);
	while (vars.bytes != ERRNUM && fmt[++vars.idx])
	{
		flags = init_flags();
		vars.c = fmt[vars.idx + 1];
		if (fmt[vars.idx] == '%')
		{
			err_check(&vars, &flags);
			vars.idx++;
		}
		else
			err_print(&vars);
	}
	va_end(vars.args);
	va_end(vars.copy);
	return (vars.bytes);
}
