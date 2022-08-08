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

static int	ft_check(t_vars *vars)
{
	if (vars->c == '%')
		return (ft_char('%'));
	if (vars->c == 'c')
		return (ft_char(va_arg(vars->args, int)));
	if (vars->c == 's')
		return (ft_string(va_arg(vars->args, char *)));
	if (vars->c == 'd' || vars->c == 'i')
		return (ft_nbrbase(va_arg(vars->args, int), 10, vars->c));
	if (vars->c == 'u')
		return (ft_nbrbase(va_arg(vars->args, int), 10, vars->c));
	if (vars->c == 'p')
		return (ft_vptr(va_arg(vars->args, t_unll)));
	if (vars->c == 'x' || vars->c == 'X')
		return (ft_nbrbase(va_arg(vars->args, unsigned int), 16, vars->c));
	return (0);
}

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
			vars.bytes += ft_check(&vars);
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
