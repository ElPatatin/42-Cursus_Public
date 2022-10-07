/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:32:26 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 09:54:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_vars	ft_init_vars(const char *fmt);
static int		ft_check(t_vars *vars);

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

static int
	ft_check(t_vars *vars)
{
	if (vars->c == '%')
		return (ft_char('%'));
	else if (vars->c == 'c')
		return (ft_char(va_arg(vars->args, int)));
	else if (vars->c == 's')
		return (ft_string(va_arg(vars->args, char *)));
	else if (vars->c == 'd' || vars->c == 'i')
		return (ft_nbrbase(va_arg(vars->args, int), 10, vars->c));
	else if (vars->c == 'u')
		return (ft_nbrbase(va_arg(vars->args, int), 10, vars->c));
	else if (vars->c == 'p')
		return (ft_vptr(va_arg(vars->args, t_unll)));
	else if (vars->c == 'x' || vars->c == 'X')
		return (ft_nbrbase(va_arg(vars->args, unsigned int), 16, vars->c));
	else
		return (0);
	return (1);
}

static
	t_vars	ft_init_vars(const char *fmt)
{
	t_vars	vars;

	vars.idx = -1;
	vars.bytes = 0;
	vars.str = (char *)fmt;
	vars.fcount = 0;
	return (vars);
}
