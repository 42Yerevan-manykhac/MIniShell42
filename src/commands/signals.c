#include "minishell.h"

// int handle(int n)
// {
//     if(n == SIGINT)
//     {

//     }
// }

void handleterm(int s)
{
    (void)s;
    write(1, "\n", 1);
    rl_on_new_line();
    rl_redisplay();
}

void    ft_signal_handling(int sig)
{
    (void)sig;
    handle_ctrl_d(sig);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, handleterm);
}

void    handle_ctrl_d(int sig)
{
    struct termios _term;
    
    tcgetattr(0, &_term);
    if (sig == 0)
    {
        printf("mta stex\n");
        _term.c_cflag &= ~ECHOCTL;
        tcsetattr(0, TCSANOW, &_term);
    }
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