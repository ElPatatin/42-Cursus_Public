/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:46:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 21:30:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	aux_print_nbr(char *str);

ssize_t
	print_ptr(t_ull nbr, t_vars *vars, t_flags *flags)
{
	char	*str;
	ssize_t	len;

	str = NULL;
	err_hex_preffix(vars, flags);
	if (vars->bytes == ERRNUM)
		return (ERRNUM);
	str = ft_ulltoa(nbr, STR_BASE16L);
	if (!str)
		return (ft_clean_str(&str));
	len = ft_strlen(str);
	if (print_string(str) == ERRNUM)
		return (ft_clean_str(&str));
	free(str);
	str = NULL;
	return (len);
}

ssize_t
	print_nbr(t_ll nbr, t_vars *vars, t_flags *flags)
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
		return (ft_clean_str(&str));
	len = ft_strlen(str);
	len = aux_check_param_zeros(vars, flags, str[0], len);
	if (len == ERRNUM)
		ft_clean_str(&str);
	if (aux_print_nbr(str) == ERRNUM)
		return (ft_clean_str(&str));
	ft_clean_str(&str);
	return (len);
}

ssize_t
	print_hex(t_ll nbr, t_vars *vars, t_flags *flags)
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
		return (ft_clean_str(&str));
	if (!(str[0] == '0' && !str[1]))
		err_hex_preffix(vars, flags);
	len = ft_strlen(str);
	if (print_string(str) == ERRNUM)
		return (ft_clean_str(&str));
	free(str);
	str = NULL;
	return (len);
}

static ssize_t
	aux_print_nbr(char *str)
{
	if (str[0] == '-')
	{
		if (print_string(&str[1]) == ERRNUM)
			return (ERRNUM);
	}
	else
		if (print_string(str) == ERRNUM)
			return (ERRNUM);
	return (0);
}
