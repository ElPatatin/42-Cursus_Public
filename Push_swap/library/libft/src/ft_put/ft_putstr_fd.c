/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:54:44 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 06:00:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_putstr_fd(char	*str, int fd)
{
	unsigned int	i;

	i = 0;
	if (!str)
	{	
		if (write(fd, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (str[i])
		if (write(fd, &str[i++], sizeof(char)) != sizeof (char))
			return (-1);
	return (ft_strlen(str));
}
