/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:58:10 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/13 19:22:38 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(int pid, char *msg);
void	ft_message_handler(int pid, unsigned char msg);

int	main(int ac, char **av)
{
	char	*line;

	if (ac != 2)
		error_handler(ERRCODE1);
	else if (!ft_str_isdigit(av[1]))
		error_handler(ERRCODE2);
	else if ((ft_strlen(av[1]) <= 4) && (ft_strlen(av[1]) >= 5))
		error_handler(ERRCODE2);
	line = get_next_line(STDIN_FILENO);
	signal(SIGUSR1, &ft_handler);
	signal(SIGUSR2, &ft_handler);
	while (line)
	{
		ft_send_message(ft_atoi(av[1]), line);
		ft_printf("\n");
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	ft_message_handler(ft_atoi(av[1]), '\0');
	while (TRUE)
		pause();
	return (0);
}

void
	ft_send_message(int pid, char *msg)
{
	char	*newline;
	ssize_t	i;

	newline = " > ";
	i = -1;
	while (newline[++i])
		ft_message_handler(pid, newline[i]);
	i = -1;
	while (msg[++i])
		ft_message_handler(pid, msg[i]);
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
		usleep(150);
		count >>= 1;
	}
}
