/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/18 14:09:39 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/21 11:49:20 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	bit_walk = 0;
	static int	c = 0;

	if (signal == SIGUSR1)
		c |= (1 << bit_walk);
	bit_walk++;
	if (bit_walk == 8)
	{
		write(1, &c, 1);
		bit_walk = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
	}
	return (0);
}
