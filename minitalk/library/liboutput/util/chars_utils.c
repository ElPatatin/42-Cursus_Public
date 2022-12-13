/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:27:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 21:30:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t
	print_char(unsigned char c)
{
	if (write(STDOUT_FILENO, &c, sizeof(char)) < FALSE)
		return (ERRNUM);
	return (1);
}

ssize_t
	print_string(char *str)
{
	ssize_t	i;

	i = -1;
	if (!str)
	{
		if (write(STDOUT_FILENO, NLLMSG, sizeof(char) * ft_strlen(NLLMSG))
			< FALSE)
			return (ERRNUM);
		return (ft_strlen(NLLMSG));
	}
	while (str[++i])
	{
		if (write(STDOUT_FILENO, &str[i], sizeof(char)) < FALSE)
			return (ERRNUM);
	}
	return (ft_strlen(str));
}
