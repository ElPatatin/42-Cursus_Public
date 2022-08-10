/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:34:25 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/09 14:34:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_print_check(t_vars *vars)
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

static int	ft_get_vars(t_vars *vars)
{
	if (vars->c == '-')
		vars->minus = 1;
	else if (vars->c == '0')
		vars->zero = 1;
	else if (vars->c == '.')
		vars->dot = 1;
	else if (vars->c == '#')
		vars->hastag = 1;
	else if (vars->c == ' ')
		vars->space = 1;
	else if (vars->c == '+')
		vars->plus = 1;
	else
		return (0);
	return (1);
}

int	ft_check(t_vars *vars, const char *fmt)
{
	(void) fmt;
	while (ft_get_vars(vars) == 1)
		vars->i = vars->i++;
	return (ft_print_check(vars));
}
