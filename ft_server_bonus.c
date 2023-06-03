/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:38:05 by myagiz            #+#    #+#             */
/*   Updated: 2023/03/02 11:59:46 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n", RED, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s\n", RED, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s\n", RED, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n", RED, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n", RED, END);
	ft_printf("\t%s⊱ ──────────────────────  {BONUS}  ─────────────────────── ⊰\
			", BLUE, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: myagiz%s\n", BLUE, pid, END,
		BLUE, END);
	ft_printf("\t%s⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n", BLUE, END);
	ft_printf("%sWriting...\n", GREEN, END);
	ft_printf("%s\n", END);
}

void	ft_action(int signum, siginfo_t *info, void *context)
{
	static char		c = 0;
	static pid_t	client_id = 0;
	static int		i = 0;

	(void)context;
	client_id = info->si_pid;
	c |= (signum == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			ft_printf("\n");
			kill(client_id, SIGUSR1);
			client_id = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = ft_action;
	act.sa_flags = SA_SIGINFO;
	display_banner(getpid());
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
	{
		pause();
	}
	return (0);
}
