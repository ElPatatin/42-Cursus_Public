/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_utils_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:27:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/07 12:58:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

ssize_t
	print_char_fd(unsigned char c, t_vars *vars)
{
	if (write(vars->fd, &c, sizeof(char)) < FALSE)
		return (ERRNUM);
	return (1);
}

ssize_t
	print_string_fd(char *str, t_vars *vars)
{
	ssize_t	i;

	i = -1;
	if (!str)
	{
		if (write(vars->fd, NLLMSG, sizeof(char) * ft_strlen(NLLMSG))
			< FALSE)
			return (ERRNUM);
		return (ft_strlen(NLLMSG));
	}
	while (str[++i])
	{
		if (write(vars->fd, &str[i], sizeof(char)) < FALSE)
			return (ERRNUM);
	}
	return (ft_strlen(str));
}
