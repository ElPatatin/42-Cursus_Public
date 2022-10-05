/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:29:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/09/30 16:45:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_error_handler(int i)
{
	if (i == ERRCODE0)
		ft_printf("%s", ERR_MSG);
	else if (i == ERRCODE1)
		ft_printf("%s", ERR_MSG1);
	else if (i == ERRCODE2)
		ft_printf("%s", ERR_MSG2);
	else if (i == ERRCODE3)
		ft_printf("%s", ERR_MSG3);
	else if (i == ERRCODE4)
		ft_printf("%s", ERR_MSG4);
	else if (i == ERRCODE5)
		ft_printf("%s", ERR_MSG5);
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
	if (sig == SIGUSR1)
	{
		usleep(50);
		ft_printf("%s", VLD_MSG1);
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("%s", VLD_MSG2);
		exit (EXIT_SUCCESS);
	}
}
