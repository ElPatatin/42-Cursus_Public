/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:25:23 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/02/08 17:57:39 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(int pid, char *msg);
void	ft_message_handler(int pid, unsigned char msg);

int	main(int ac, char **av)
{
	if (ac != 3)
		error_handler(ERRCODE1);
	else if (!ft_str_isdigit(av[1]))
		error_handler(ERRCODE2);
	else if ((ft_strlen(av[1]) <= 4) && (ft_strlen(av[1]) >= 5))
		error_handler(ERRCODE2);
	signal(SIGUSR1, &ft_handler);
	signal(SIGUSR2, &ft_handler);
	ft_send_message(ft_atoi(av[1]), av[2]);
	while (TRUE)
		pause();
	return (0);
}

void
	ft_send_message(int pid, char *msg)
{
	char	*newline;
	ssize_t	idx;

	newline = "\n > ";
	idx = -1;
	while (newline[++idx])
		ft_message_handler(pid, newline[idx]);
	idx = -1;
	while (msg[++idx])
		ft_message_handler(pid, msg[idx]);
	ft_message_handler(pid, '\0');
}

void
	ft_message_handler(int pid, unsigned char msg)
{
	t_unt	count;

	count = 1 << 7;
	while (count)
	{
		if (msg & count)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_handler(ERRCODE0);
			pause();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_handler(ERRCODE0);
			pause();
		}
		usleep(320);
		count >>= 1;
	}
}
