/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:21:45 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/07 14:30:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

t_vars
	init_vars_fd(const char *fmt, int fd)
{
	t_vars	vars;

	vars.fd = fd;
	vars.ref = 0;
	vars.idx = -1;
	vars.count = 0;
	vars.errchk = 0;
	vars.bytes = 0;
	vars.str = (char *)fmt;
	vars.nbr = 0;
	vars.prs = 0;
	return (vars);
}

t_flags
	init_flags_fd(void)
{
	t_flags	flags;

	flags.minus = FALSE;
	flags.zero = FALSE;
	flags.dot = FALSE;
	flags.hash = FALSE;
	flags.space = FALSE;
	flags.plus = FALSE;
	flags.sign = FALSE;
	flags.hexpreffix = FALSE;
	return (flags);
}

int
	get_flags_fd(t_vars *vars, t_flags *flags)
{
	if (vars->c == '-')
		flags->minus = TRUE;
	else if (vars->c == '0')
		flags->zero = TRUE;
	else if (vars->c == '#')
		flags->hash = TRUE;
	else if (vars->c == ' ')
		flags->space = TRUE;
	else if (vars->c == '+')
		flags->plus = TRUE;
	else
		return (FALSE);
	return (TRUE);
}
