/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:25:23 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/06 01:46:26 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_message_handler(int pid, unsigned char msg)
{
	t_unt	count;

	count = 1 << 7;
	while (count)
	{
		if (msg & count)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error_handler(ERRCODE0);
			pause();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error_handler(ERRCODE0);
			pause();
		}
		usleep(150);
		count >>= 1;
	}
}

void	ft_send_message(int pid, char *msg)
{
	ssize_t	i;

	i = -1;
	while (msg[++i])
		ft_message_handler(pid, msg[i]);
	ft_message_handler(pid, msg[i]);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_error_handler(ERRCODE1);
	else if (!ft_str_isdigit(av[1]))
		ft_error_handler(ERRCODE2);
	else if (!((ft_strlen(av[1]) <= 4)
			&& (ft_strlen(av[1]) >= 5)))
		ft_error_handler(ERRCODE2);
	signal(SIGUSR1, &ft_handler);
	signal(SIGUSR2, &ft_handler);
	ft_send_message(ft_atoi(av[1]), av[2]);
	while (TRUE)
		pause();
	return (0);
}
