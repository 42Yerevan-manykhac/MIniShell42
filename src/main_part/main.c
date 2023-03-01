
#include "minishell.h"

int exit_code = 0;

int	main(int arg_nb, char **argv, char **env)
{
	(void)arg_nb;
	(void)argv;
	char		*str;
	int    in_copy;
	int    out_copy;
	char *esim;
	t_tokens	*token;
	
	t_env		*s_env;
	(void)esim;
	(void)token;
	(void)s_env;
	(void)env;
	//print_logo();
	s_env = malloc(sizeof(t_env));
	// ft_signal_handling(0);
	env_init(env, &s_env);
	shell_level(&s_env);
	while (1)
	{
		in_copy = dup(0);
		out_copy = dup(1);
		str = readline ("Minishell$> ");
		// if(str == 0)
		//  	handleterm(0);
		printf("\033[0;35m");
		if (str)
			add_history(str);
		else
			break;
		//rl_catch_signals = 0;
		gen_parsing(&token, &s_env, &str);
		if (token)
		{
			if (token->token_count > 1)
				running_pipe(&token, &s_env);
			else	
				running(&token, &s_env );
		}
		dup2(in_copy, 0);
		dup2(out_copy,1);
		printf("\033[0;36m"); 
		free_t_list(&token);
		free(str);
	}
	return (0);
}


// redirectionneri qanaky hashvel u verjni depqum dup anel