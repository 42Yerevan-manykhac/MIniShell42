
#include "minishell.h"

int exit_code = 0;

int	main(int arg_nb, char **argv, char **env)
{
	(void)arg_nb;
	(void)argv;
	char		*str;
	int    in_copy;
	char *esim;
	t_tokens	*token;
	t_env		*s_env;
	(void)esim;
	(void)token;
	(void)s_env;
	(void)env;
	// print_logo();
	s_env = malloc(sizeof(t_env));
	ft_signal_handling(0);
	env_init(env, &s_env);
	while (1)
	{
		in_copy = dup(0);
		str = readline ("Minishell$> ");
		if(str == 0)
		 	handleterm(0);
		printf("\033[0;35m");
		if (str)
			add_history(str);
		else
			break;
		//rl_catch_signals = 0;
		gen_parsing(&token, &s_env, &str);
		running(&token, &s_env);
		dup2(in_copy, 0);
	
	printf("\033[0;36m"); 
	// printf("rdl = %s\n", token->rdl);
	// free(token->rdl);
	// printf("rdl2 = %s\n", token->rdl);
	free_t_list(&token);
	free(str);
	}
	return (0);
}
