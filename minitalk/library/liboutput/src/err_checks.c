/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:08:31 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 21:28:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	err_check(t_vars *vars, t_flags *flags)
{
	vars->errchk = ft_parse_params(vars, flags);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}

void
	err_print(t_vars *vars)
{
	vars->errchk = print_char(vars->str[vars->idx]);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}

void
	err_margin(t_vars *vars, t_flags *flags)
{
	vars->errchk = ft_check(vars, flags);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}

void
	err_width(t_vars *vars, t_flags *flags)
{
	if (flags->zero == TRUE && flags->minus == FALSE
		&& (vars->ref >= 4 && vars->ref <= 8))
		vars->errchk = add_zeros(vars, flags);
	else
		vars->errchk = add_width(vars, flags);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}

void
	err_hex_preffix(t_vars *vars, t_flags *flags)
{
	vars->errchk = print_hex_prefix(vars, flags);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}
