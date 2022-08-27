/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:34:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 18:46:47 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

void	ft_width_zero(t_vars *vars, t_flags *flags)
{
	t_unt	i;

	while (vars->str[vars->idx + 1] == '-')
		vars->idx++;
	while (vars->str[vars->idx + 1] == '0')
		vars->idx++;
	i = ft_atoi(vars->str + (vars->idx + 1));
	vars->c = vars->str[vars->idx + ft_nbrlen(i) + 1];
	vars->idx += ft_nbrlen(i);
	if (flags->minus == 1)
		vars->bytes += ft_print_check(vars);
	if (vars->c == 's' || vars->c == 'c' || vars->c == '%')
	{
		while (i--)
			vars->bytes += write(STDOUT_FILENO, "0", sizeof(char));
	}
	else
	{
		i -= vars->fcount;
		while (i--)
			vars->bytes += write(STDOUT_FILENO, "0", sizeof(char));
	}
}

void	ft_width(t_vars *vars, t_flags *flags)
{
	t_unt	i;

	while (vars->str[vars->idx + 1] == '-')
		vars->idx++;
	i = ft_atoi(vars->str + (vars->idx + 1));
	vars->c = vars->str[vars->idx + ft_nbrlen(i) + 1];
	vars->idx += ft_nbrlen(i);
	if (flags->minus == 1)
		vars->bytes += ft_print_check(vars);
	if (vars->c == 's' || vars->c == 'c' || vars->c == '%')
	{
		while (i--)
			vars->bytes += write(STDOUT_FILENO, " ", sizeof(char));
	}
	else
	{
		i -= vars->fcount;
		while (i--)
			vars->bytes += write(STDOUT_FILENO, " ", sizeof(char));
	}
}

// static int	ft_control(t_vars *vars)
// {
// 	  if (vars->c == '%' || vars->c == 'c' || vars->c == 's')
// 		return (ft_strlen(va_arg(vars->args, char *)));
// 	else
// 		return (ft_nbrlen(va_arg(vars->args, t_ll)));
// }