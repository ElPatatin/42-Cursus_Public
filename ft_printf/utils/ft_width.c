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

void ft_width(t_vars *vars)
{
    t_unt	i;

	i = 0;
    i = ft_atoi(vars->str + (vars->idx + 1));
	vars->c = vars->str[vars->idx + ft_nbrlen(i) + 1];
	vars->idx += ft_nbrlen(i);
    while (i--)
        vars->bytes += write(STDOUT_FILENO, " ", sizeof(char));
}