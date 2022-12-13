/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:29:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/13 19:28:43 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void
	error_buffer(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	error_handler(ERRCODE5);
}

void
	error_handler(int err)
{
	if (err == ERRCODE0)
		ft_printf_fd(STDERR_FILENO, "%s", ERR_MSG);
	else if (err == ERRCODE1)
		ft_printf_fd(STDERR_FILENO, "%s", ERR_MSG1);
	else if (err == ERRCODE2)
		ft_printf_fd(STDERR_FILENO, "%s", ERR_MSG2);
	else if (err == ERRCODE3)
		ft_printf_fd(STDERR_FILENO, "%s", ERR_MSG3);
	else if (err == ERRCODE4)
		ft_printf_fd(STDERR_FILENO, "%s", ERR_MSG4);
	else if (err == ERRCODE5)
		ft_printf_fd(STDERR_FILENO, "%s", ERR_MSG5);
	exit(EXIT_FAILURE);
}

int
	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void
	ft_handler(int sig)
{
	static long	count = 0;

	if (sig == SIGUSR1)
	{
		++count;
		usleep(10);
		ft_printf("%sBit %s[%d] %sconfirmed.%s\r", CYAN, RED, count, CYAN, END);
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("%sTotal bits confirmed: %s[%d]%s\n", CYAN, RED, count, END);
		usleep(100);
		exit (EXIT_SUCCESS);
	}
}
