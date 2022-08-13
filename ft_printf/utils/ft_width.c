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

void ft_width(t_vars *vars)
{
	t_unt	i;
	t_unt	j;
	char	*s;

	s = va_arg(vars->args, char *);
	j = ft_strlen(s);
	while (vars->str[vars->idx + 1] == '-')
		vars->idx++;
	i = ft_atoi(vars->str + (vars->idx + 1));
	vars->c = vars->str[vars->idx + ft_nbrlen(i) + 1];
	vars->idx += ft_nbrlen(i);
	if (vars->minus == 1)
		vars->bytes += ft_print_check(vars);
	if (vars->c == 's' || vars->c == 'c' || vars->c == '%')
		while (i - j)
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