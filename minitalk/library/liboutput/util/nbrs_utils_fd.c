/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs_utils_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:46:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/07 16:21:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

static ssize_t	aux_print_nbr_fd(char *str, t_vars *vars);

ssize_t
	print_ptr_fd(t_ull nbr, t_vars *vars, t_flags *flags)
{
	char	*str;
	ssize_t	len;

	str = NULL;
	err_hex_preffix_fd(vars, flags);
	if (vars->bytes == ERRNUM)
		return (ERRNUM);
	str = ft_ulltoa(nbr, STR_BASE16L);
	if (!str)
		return (ft_clean_str_fd(&str));
	len = ft_strlen(str);
	if (print_string_fd(str, vars) == ERRNUM)
		return (ft_clean_str_fd(&str));
	free(str);
	str = NULL;
	return (len);
}

ssize_t
	print_nbr_fd(t_ll nbr, t_vars *vars, t_flags *flags)
{
	char	*str;
	ssize_t	len;

	str = NULL;
	if (nbr < 0 && (vars->ref == 6))
		nbr = ft_stou(nbr);
	if (vars->ref == 4 || vars->ref == 5)
		str = ft_lltoa(nbr, STR_BASE10);
	else if (vars->ref == 6)
		str = ft_lltoa(nbr, STR_BASE10);
	if (!str)
		return (ft_clean_str_fd(&str));
	len = ft_strlen(str);
	len = aux_check_param_zeros_fd(vars, flags, str[0], len);
	if (len == ERRNUM)
		ft_clean_str_fd(&str);
	if (aux_print_nbr_fd(str, vars) == ERRNUM)
		return (ft_clean_str_fd(&str));
	ft_clean_str_fd(&str);
	return (len);
}

ssize_t
	print_hex_fd(t_ll nbr, t_vars *vars, t_flags *flags)
{
	char	*str;
	ssize_t	len;

	str = NULL;
	if (vars->bytes == ERRNUM)
		return (ERRNUM);
	if (vars->ref == 7)
		str = ft_ulltoa(nbr, STR_BASE16L);
	else if (vars->ref == 8)
		str = ft_ulltoa(nbr, STR_BASE16U);
	if (!str)
		return (ft_clean_str_fd(&str));
	if (!(str[0] == '0' && !str[1]))
		err_hex_preffix_fd(vars, flags);
	len = ft_strlen(str);
	if (print_string_fd(str, vars) == ERRNUM)
		return (ft_clean_str_fd(&str));
	free(str);
	str = NULL;
	return (len);
}

static ssize_t
	aux_print_nbr_fd(char *str, t_vars *vars)
{
	if (str[0] == '-')
	{
		if (print_string_fd(&str[1], vars) == ERRNUM)
			return (ERRNUM);
	}
	else
		if (print_string_fd(str, vars) == ERRNUM)
			return (ERRNUM);
	return (0);
}
