/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:54:30 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:30:44 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putstr(char	*str)
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
