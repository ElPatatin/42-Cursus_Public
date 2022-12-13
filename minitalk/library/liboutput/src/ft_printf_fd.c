/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:36:11 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/07 14:30:41 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int
	ft_printf_fd(int fd, const char *fmt, ...)
{
	t_vars	vars;
	t_flags	flags;

	vars = init_vars_fd(fmt, fd);
	va_start(vars.args, fmt);
	va_copy(vars.copy, vars.args);
	while (vars.bytes != ERRNUM && fmt[++vars.idx])
	{
		flags = init_flags_fd();
		vars.c = fmt[vars.idx + 1];
		if (fmt[vars.idx] == '%')
		{
			err_check_fd(&vars, &flags);
			vars.idx++;
		}
		else
			err_print_fd(&vars);
	}
	va_end(vars.args);
	va_end(vars.copy);
	return (vars.bytes);
}
