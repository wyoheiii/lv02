/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:26:28 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/02 13:54:00 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_sig;

void	print_pid(void)
{
	ft_putstr_fd("pid:", 1);
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n", 1);
}

void	signal_handler(int	signal, siginfo_t	*dont_use, void	*dont_use_it)
{
	(void)dont_use;
	(void)dont_use_it;
	if (signal == SIGUSR2)
		g_sig.c += 1 << --g_sig.bit;
	else if (signal == SIGUSR1)
		--g_sig.bit;
	if (g_sig.bit == 0)
	{
		write(1, &g_sig.c, 1);
		g_sig.bit = 8;
		g_sig.c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	print_pid();
	g_sig.bit = 8;
	g_sig.c = 0;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
