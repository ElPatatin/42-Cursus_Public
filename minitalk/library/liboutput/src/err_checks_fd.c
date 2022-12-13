/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checks_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:08:31 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/07 14:32:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void
	err_check_fd(t_vars *vars, t_flags *flags)
{
	vars->errchk = parse_params_fd(vars, flags);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}

void
	err_print_fd(t_vars *vars)
{
	vars->errchk = print_char_fd(vars->str[vars->idx], vars);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}

void
	err_margin_fd(t_vars *vars, t_flags *flags)
{
	vars->errchk = check_fd(vars, flags);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}

void
	err_width_fd(t_vars *vars, t_flags *flags)
{
	if (flags->zero == TRUE && flags->minus == FALSE
		&& (vars->ref >= 4 && vars->ref <= 8))
		vars->errchk = add_zeros_fd(vars, flags);
	else
		vars->errchk = add_width_fd(vars, flags);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}

void
	err_hex_preffix_fd(t_vars *vars, t_flags *flags)
{
	vars->errchk = print_hex_prefix_fd(vars, flags);
	if (vars->errchk == ERRNUM)
		vars->bytes = vars->errchk;
	else
		vars->bytes += vars->errchk;
}
