/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:25:13 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/11 17:26:38 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int handle(int n)
// {
//     if(n == SIGINT)
//     {

//     }
// }

void	handleterm(int s)
{
	(void)s;
	
	write(1, "\n", 1);
	rl_on_new_line ();
	rl_redisplay ();
}

void	handle_ctrl_d(int sig)
{
	struct	termios _term;

	tcgetattr(0, &_term);
	if (sig == 0)
	{
		_term.c_cflag &= ~ECHOCTL;
		tcsetattr(0, TCSANOW, &_term);
	}
}

void	ft_signal_handling(int sig)
{
	(void)sig;
	
	handle_ctrl_d(sig);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handleterm);
}



// struct termios {
// 	tcflag_t c_iflag;
// 	tcflag_t c_oflag;
// 	tcflag_t c_cflag;
// 	tcflag_t c_lflag;
// 	cc_t c_cc[NCCS];
// 	speed_t c_ispeed;
// 	speed_t c_ospeed;
// };