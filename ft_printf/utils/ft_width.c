/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:34:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/09 14:34:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

static int	ft_control(t_vars *vars);

void ft_width(t_vars *vars, t_flags *flags)
{
	t_unt	i;

	vars->wcount = ft_control(vars);
	while (vars->str[vars->idx + 1] == '-')
		vars->idx++;
	i = ft_atoi(vars->str + (vars->idx + 1));
	vars->c = vars->str[vars->idx + ft_nbrlen(i) + 1];
	vars->idx += ft_nbrlen(i);
	if (flags->minus == 1)
		vars->bytes += ft_print_check(vars);
	if (vars->c == 's' || vars->c == 'c' || vars->c == '%')
		while (i - vars->wcount)
		{
			vars->bytes += write(STDOUT_FILENO, " ", sizeof(char));
			--i;
		}
	else
		while (i - (ft_nbrlen(i) + vars->fcount + 2))
		{
			vars->bytes += write(STDOUT_FILENO, " ", sizeof(char));
			--i;
		}
}

static int	ft_control(t_vars *vars)
{
	  if (vars->c == '%' || vars->c == 'c' || vars->c == 's')
		return (ft_strlen(vars->args));
	else
		return (ft_nbrlen(vars->args));
}