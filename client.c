/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/18 14:29:20 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/20 17:56:23 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		bit++;
	}
}

int	check_args(int argc, char **argv)
{
	int	argv_pid_count;

	argv_pid_count = 0;
	if (argc < 3)
	{
		ft_printf("Too few arguments!\n");
		return (1);
	}
	while (argv[1][argv_pid_count])
	{
		if (ft_strchr("0123456789,", argv[1][argv_pid_count]) == 0)
		{
			ft_printf("Invalid PID format!\n");
			return (1);
		}
		argv_pid_count++;
	}
	if (ft_atol(argv[1]) == 0)
	{
		ft_printf("Invalid PID!\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		count;

	count = 0;
	if (check_args(argc, argv) == 1)
		return (1);
	pid = ft_atoi(argv[1]);
	while (argv[2][count] != '\0')
	{
		send_char(pid, argv[2][count]);
		count++;
	}
	return (0);
}
