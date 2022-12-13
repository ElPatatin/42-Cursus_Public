/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:47:10 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/08 23:47:38 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int
	parse_params_fd(t_vars *vars, t_flags *flags)
{
	vars->nbr = 0;
	vars->prs = 0;
	vars->count = 0;
	vars->ref = input_check_fd(vars->c);
	if (vars->ref >= 0 && vars->ref <= 8)
		return (check_fd(vars, flags));
	else
	{
		while (get_flags_fd(vars, flags))
		{
			vars->idx++;
			vars->c = vars->str[vars->idx + 1];
		}
		while (ft_isdigit(vars->str[++vars->idx]))
			++vars->count;
		vars->nbr = ft_atoll(&vars->str[vars->idx - vars->count], 10);
		vars->c = vars->str[vars->idx];
		vars->idx--;
		vars->ref = input_check_fd(vars->c);
		return (get_params_fd(vars, flags));
	}
	return (ERRNUM);
}

int
	get_params_fd(t_vars *vars, t_flags *flags)
{
	err_width_fd(vars, flags);
	if (vars->bytes == ERRNUM)
		return (ERRNUM);
	if (flags->minus == TRUE)
		return (0);
	return (check_fd(vars, flags));
}

int
	check_fd(t_vars *vars, t_flags *flags)
{
	if (vars->ref == 0)
		return (print_char_fd('%', vars));
	else if (vars->ref == 1)
		return (print_char_fd(va_arg(vars->args, int), vars));
	else if (vars->ref == 2)
		return (print_string_fd(va_arg(vars->args, char *), vars));
	else if (vars->ref == 3)
		return (print_ptr_fd(va_arg(vars->args, t_ull), vars, flags));
	else if (vars->ref >= 4 && vars->ref <= 6)
		return (print_nbr_fd(va_arg(vars->args, int), vars, flags));
	else if (vars->ref == 7 || vars->ref == 8)
		return (print_hex_fd(va_arg(vars->args, unsigned int), vars, flags));
	return (ERRNUM);
}
