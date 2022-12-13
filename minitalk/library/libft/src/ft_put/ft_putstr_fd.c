/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:54:44 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:48:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (write(fd, &str[i++], sizeof(char)) < 0)
			return (-1);
	return (ft_strlen(str));
}
