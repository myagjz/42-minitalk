/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:37:53 by myagiz            #+#    #+#             */
/*   Updated: 2023/03/02 16:39:59 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	ft_character(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= 0 && str[i] <= 127))
		{
			ft_printf("%sError\n", RED);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("%sclient: unexpected error.\n", RED);
		return (0);
	}
	if (ft_character(av[2]))
		return (0);
	ft_kill(ft_atoi(av[1]), av[2]);
	return (0);
}
