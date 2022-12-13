/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:36:13 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/08 23:47:30 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int
	input_check_fd(char c)
{
	size_t	idx;
	char	*cmp;

	idx = -1;
	cmp = FTRREF;
	while (++idx < ft_strlen(cmp))
		if (c == cmp[idx])
			return (idx);
	return (ERRNUM);
}

ssize_t
	ft_clean_str_fd(char **str)
{
	free(*str);
	str = NULL;
	return (ERRNUM);
}

t_ll
	aux_check_param_zeros_fd(t_vars *vars, t_flags *flags, char c, t_ll len)
{
	if (flags->sign == FALSE && (vars->ref == 4 || vars->ref == 5))
	{
		if (c == '-')
		{
			if (print_char_fd('-', vars) == ERRNUM)
				return (ERRNUM);
			flags->sign = TRUE;
		}
		else if (ft_isdigit(c) && flags->plus == TRUE)
		{	
			if (print_char_fd('+', vars) == ERRNUM)
				return (ERRNUM);
			++len;
			flags->sign = TRUE;
		}
		else if (ft_isdigit(c) && flags->space == TRUE)
		{
			if (print_char_fd(' ', vars) == ERRNUM)
				return (ERRNUM);
			++len;
			flags->sign = TRUE;
		}
	}
	return (len);
}

ssize_t
	print_hex_prefix_fd(t_vars *vars, t_flags *flags)
{
	if (flags->hexpreffix == TRUE)
		return (FALSE);
	else if (flags->hash == FALSE && (vars->ref == 7 || vars->ref == 8))
		return (FALSE);
	else if (flags->hash == TRUE && (vars->ref != 7 && vars->ref != 8))
		return (ERRNUM);
	if (vars->ref == 7)
	{
		if (print_string_fd(HEXPRE, vars) == ERRNUM)
			return (ERRNUM);
	}
	else if (vars->ref == 8)
	{
		if (print_string_fd(HEXPREU, vars) == ERRNUM)
			return (ERRNUM);
	}
	else
		if (print_string_fd(HEXPRE, vars) == ERRNUM)
			return (ERRNUM);
	flags->hexpreffix = TRUE;
	return (ft_strlen(HEXPRE));
}
