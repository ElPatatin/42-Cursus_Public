/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:54:30 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/07/16 16:54:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_ft.h"

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
