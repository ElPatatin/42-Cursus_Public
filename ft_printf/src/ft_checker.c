/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:34:25 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/26 17:14:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_get_vars(t_vars *vars, t_flags *flags);

int	ft_check(t_vars *vars)
{
	t_flags	flags;

	while (ft_get_vars(vars, &flags) == 1)
	{
		vars->idx++;
		vars->c = vars->str[vars->idx + 1];
		vars->fcount++;
	}
	if (vars->str[vars->idx + 1] >= '1' && vars->str[vars->idx + 1] <= '9')
		ft_width(vars, &flags);
	if (flags.minus == 1)
		return (vars->bytes);
	return (ft_print_check(vars));
}

int	ft_print_check(t_vars *vars)
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
	else if (vars->c == 'a')
		return (ft_char("\a"));
	else
		return (0);
	return (1);
}

static int	ft_get_vars(t_vars *vars, t_flags *flags)
{
	if (vars->c == '-')
		flags->minus = 1;
	else if (vars->c == '0')
		flags->zero = 1;
	else if (vars->c == '.')
		flags->dot = 1;
	else if (vars->c == '#')
		flags->hastag = 1;
	else if (vars->c == ' ')
		flags->space = 1;
	else if (vars->c == '+')
		flags->plus = 1;
	else
		return (0);
	return (1);
}
