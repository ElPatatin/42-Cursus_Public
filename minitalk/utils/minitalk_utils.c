/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:29:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/07 17:41:21 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_error_handler(int i)
{
	if (i == ERRCODE0)
		write(STDERR_FILENO, ERR_MSG, sizeof(char) * ft_strlen(ERR_MSG));
	else if (i == ERRCODE1)
		write(STDERR_FILENO, ERR_MSG1, sizeof(char) * ft_strlen(ERR_MSG1));
	else if (i == ERRCODE2)
		write(STDERR_FILENO, ERR_MSG2, sizeof(char) * ft_strlen(ERR_MSG2));
	else if (i == ERRCODE3)
		write(STDERR_FILENO, ERR_MSG3, sizeof(char) * ft_strlen(ERR_MSG3));
	else if (i == ERRCODE4)
		write(STDERR_FILENO, ERR_MSG4, sizeof(char) * ft_strlen(ERR_MSG4));
	else if (i == ERRCODE5)
		write(STDERR_FILENO, ERR_MSG5, sizeof(char) * ft_strlen(ERR_MSG5));
	exit(EXIT_FAILURE);
}

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_handler(int sig)
{
	static long	count = 0;

	if (sig == SIGUSR1)
	{
		++count;
		usleep(10);
		ft_printf("\r\033[1;36mBit \033[1;31m[%d] \033[1;36mconfirmed.\033[0;39m", count);
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("\r\033[1;36mTotal bits confirmed \033[1;31m[%d].\n\033[0;39m", count);
		exit (EXIT_SUCCESS);
	}
}
