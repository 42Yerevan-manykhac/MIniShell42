
#include "minishell.h"

int exit_code = 0;

int sp_sp(char *str)
{
	char *rt;

	rt = ft_strtrim(str, " ");
	if (rt == NULL)
		return (0);
	else 
	{
		free(rt);
		return (1);
	}
}
void	handler(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	//write(1, "\n", 1);
	rl_done = 1;
	exit_code = 26354;
}

int	eshutyun(void)
{
	return (0);
}

static void	handle_sigquit(int sig)
{
	(void)sig;
	rl_redisplay();
}

void	start_signals(int exit_code)
{
	(void)exit_code;
	rl_catch_signals = 0;
	rl_event_hook = eshutyun;
	signal(SIGINT, handler);
	signal(SIGQUIT, handle_sigquit);
}

// void	handler(int sig)
// {
// 	(void)sig;
// 	rl_replace_line("", 0);
// 	//printf("ZZZZZ\n");
// 	//write(1, "\n", 1);
//  	// rl_on_new_line ();
//  	// rl_redisplay ();
// 	rl_done = 1;
// 	// exit_code = 1;
// }

int	main(int arg_nb, char **argv, char **env)
{
	(void)arg_nb;
	(void)argv;
	char		*str;
	int			in_copy;
	int			out_copy;
	t_tokens	*token;
	t_env		*s_env;

	//print_logo();
	//signal(SIGINT, &handleterm);
	//signal(SIGQUIT, SIG_IGN);
	s_env = malloc(sizeof(t_env));
	start_signals(exit_code);
	// rl_catch_signals = 0;
	//  rl_event_hook = eshutyun;
	// // rl_done = 1;
	//ft_signal_handling(0);
	env_init(env, &s_env);
	shell_level(&s_env);
	//tcgetattr(0, &inch);
	while (1)
	{
		//tcsetattr(0,0, &inch);
		in_copy = dup(0);
		out_copy = dup(1);
		str = readline ("Minishell$> ");
		// printf("\033[0;35m");
		if (str)
			add_history(str);
		else
			break ;
		if (sp_sp(str))
		{
			gen_parsing(&token, &s_env, &str);
			if (token)
			{
				if (token->token_count > 1)
					running_pipe(&token, &s_env);
				else
					running(&token, &s_env);
			}
			signal(SIGINT, &handler);
			signal(SIGQUIT, &handler);
			dup2(in_copy, 0);
			dup2(out_copy, 1);
			close(out_copy);
			// printf("\033[0;36m");
			free_t_list(&token);
		}
		free(str);
	}
	return (0);
}
