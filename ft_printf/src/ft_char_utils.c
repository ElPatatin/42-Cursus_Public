/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:11:17 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/06/11 13:11:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_string(char	*str)
{
	unsigned int	i;

	i = 0;
	if (!str)
	{	
		if (write(STDOUT_FILENO, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (str[i])
		if (write(STDOUT_FILENO, &str[i++], sizeof(char)) != sizeof (char))
			return (-1);
	return (ft_strlen(str));
}

int	ft_char(int c)
{
	if (write(STDOUT_FILENO, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (1);
}
