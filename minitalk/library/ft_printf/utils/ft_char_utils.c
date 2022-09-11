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

int	ft_char(int c)
{
	if (write(STDOUT_FILENO, &c, sizeof(char)) != sizeof(char))
		return (ERR_NUM);
	return (1);
}

int	ft_string(char	*str)
{
	unsigned int	i;

	i = 0;
	if (!str)
	{	
		if (write(STDOUT_FILENO, NLL_MSG, 6) != 6)
			return (ERR_NUM);
		return (ft_strlen(NLL_MSG));
	}
	while (str[i])
		if (write(STDOUT_FILENO, &str[i++], sizeof(char)) != sizeof (char))
			return (ERR_NUM);
	return (ft_strlen(str));
}
