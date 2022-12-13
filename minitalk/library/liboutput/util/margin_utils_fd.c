/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   margin_utils_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:34:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/07 16:22:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

static t_ll	check_param_width_fd(t_vars *vars);
static t_ll	check_param_zeros_fd(t_vars *vars, t_flags *flags);

ssize_t
	add_width_fd(t_vars *vars, t_flags *flags)
{
	t_ll	len;
	t_ll	count;

	len = check_param_width_fd(vars);
	if (len == ERRNUM)
		return (ERRNUM);
	count = 0;
	if (flags->minus == TRUE)
		err_margin_fd(vars, flags);
	if (len < vars->nbr)
	{
		while (vars->nbr && (vars->nbr-- - len))
		{
			if (print_char_fd(' ', vars) == ERRNUM)
				return (ERRNUM);
			++count;
		}
	}
	return (count);
}

ssize_t
	add_zeros_fd(t_vars *vars, t_flags *flags)
{
	t_ll	len;
	t_ll	count;

	len = check_param_zeros_fd(vars, flags);
	if (len == ERRNUM)
		return (ERRNUM);
	count = 0;
	if (len < vars->nbr)
	{
		while (vars->nbr && (vars->nbr-- - len))
		{
			if (print_char_fd('0', vars) == ERRNUM)
				return (ERRNUM);
			++count;
		}
	}
	return (count);
}

static t_ll
	check_param_width_fd(t_vars *vars)
{
	char	*str;
	t_ll	len;

	len = ERRNUM;
	str = NULL;
	if (vars->ref == 0 || vars->ref == 1)
		return (1);
	else if (vars->ref == 2)
		str = ft_strdup(va_arg(vars->copy, char *));
	else if (vars->ref == 3)
		str = ft_ulltoa(va_arg(vars->copy, t_ull), STR_BASE16L);
	else if (vars->ref == 4 || vars->ref == 5)
		str = ft_lltoa(va_arg(vars->copy, int), STR_BASE10);
	else if (vars->ref == 6)
		str = ft_ulltoa(va_arg(vars->copy, t_unt), STR_BASE10);
	else if (vars->ref == 7 || vars->ref == 8)
		str = ft_ulltoa(va_arg(vars->copy, t_unt), STR_BASE16L);
	if (!str)
		ft_clean_str_fd(&str);
	if (vars->ref == 3)
		len = ft_strlen(str) + ft_strlen(HEXPRE);
	else
		len = ft_strlen(str);
	ft_clean_str_fd(&str);
	return (len);
}

static t_ll
	check_param_zeros_fd(t_vars *vars, t_flags *flags)
{
	char	*str;
	t_ll	len;

	len = 0;
	str = NULL;
	if (vars->ref == 4 || vars->ref == 5)
		str = ft_lltoa(va_arg(vars->copy, int), STR_BASE10);
	else if (vars->ref == 6)
		str = ft_ulltoa(va_arg(vars->copy, t_unt), STR_BASE10);
	else if (vars->ref == 7 || vars->ref == 8)
		str = ft_ulltoa(va_arg(vars->copy, t_unt), STR_BASE16L);
	if (!str)
		return (ft_clean_str_fd(&str));
	len = ft_strlen(str);
	len = aux_check_param_zeros_fd(vars, flags, str[0], len);
	if ((vars->ref == 7 || vars->ref == 8) && flags->hash == TRUE)
		print_hex_prefix_fd(vars, flags);
	ft_clean_str_fd(&str);
	return (len);
}
