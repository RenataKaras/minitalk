/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/18 14:12:03 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/20 15:28:52 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include "./Libft/get_next_line.h"
# include <signal.h>

void	handler(int signal);
void	send_char(int pid, char c);
int		check_args(int argc, char **argv);

#endif
