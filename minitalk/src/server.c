/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:25:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/07 17:40:29 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	ft_print_pid(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		ft_error_handler(ERRCODE4);
	if (ft_printf("Server up and running.\nPID: %d\n", pid) == -1)
		exit(EXIT_FAILURE);
}

void	ft_message_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static char	msg = '\0';
	static int	idx = 0;

	(void)unused;
	usleep(150);
	if (signum == SIGUSR1)
	{
		msg = msg | 1 << (7 - idx);
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
			ft_error_handler(ERRCODE0);
	}
	else
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
			ft_error_handler(ERRCODE0);
	idx++;
	if (idx == 8)
	{
		ft_printf("%c", msg);
		if (msg == '\0')
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_error_handler(ERRCODE0);
		msg = '\0';
		idx = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	catch;

	UNUSED(av);
	if (ac > 1)
		return (1);
	ft_print_pid();
	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = ft_message_handler;
	if ((sigaction(SIGUSR1, &catch, 0)) == -1)
		ft_error_handler(ERRCODE0);
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		ft_error_handler(ERRCODE0);
	while (TRUE)
		pause();
	return (0);
}
