/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:25:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/13 19:29:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_print_pid(void);
void		ft_message_handler(int signum, siginfo_t *siginfo, void *unused);
void		aux_message_handler(int signum, siginfo_t *siginfo,
				char *msg, int *idx);

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
		error_handler(ERRCODE0);
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		error_handler(ERRCODE0);
	while (TRUE)
		pause();
	return (0);
}

static void
	ft_print_pid(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		error_handler(ERRCODE4);
	if (ft_printf("Server up and running.\nPID: %d\n", pid) == -1)
		exit(EXIT_FAILURE);
}

void
	ft_message_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static char	msg = '\0';
	static int	idx = 0;
	static char	*str = NULL;

	UNUSED(unused);
	usleep(100);
	aux_message_handler(signum, siginfo, &msg, &idx);
	idx++;
	if (idx == 8)
	{
		str = ft_strjoin(str, &msg);
		if (!str)
			error_buffer(&str);
		if (msg == '\0')
		{
			ft_printf("%s", str);
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				error_handler(ERRCODE0);
		}
		msg = '\0';
		idx = 0;
	}
}

void
	aux_message_handler(int signum, siginfo_t *siginfo,
		char *msg, int *idx)
{
	if (signum == SIGUSR1)
	{
		*msg = *msg | 1 << (7 - *idx);
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
			error_handler(ERRCODE0);
	}
	else
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
			error_handler(ERRCODE0);
}
