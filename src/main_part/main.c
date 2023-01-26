
#include "minishell.h"

int	main(int arg_nb, char **argv, char **env)
{
	(void)arg_nb;
	(void)argv;
	char		*str;
	t_tokens	*token;
	t_env		*s_env;
	(void)s_env;
	(void)env;
	print_logo();
	token = malloc(sizeof(t_tokens));
	token->next = NULL;
	s_env = malloc(sizeof(t_env));
	env_init(env, &s_env);
	while (1)
	{
		str = readline ("Minishell$> ");
		printf("\033[0;35m");
		if (str)
			add_history(str);
	heredoc(str);
		//redirection_input(str, 1);
		//gen_parsing(&token, &s_env, str);
		//printf("\n\nstr = %s\n\n", str);
		//unset_cmd(&s_env, str);
		//env_cmd(s_env);
	//	cd_cmd(&s_env, &str);
		//export_cmd(&s_env,str); (done( check only_export ))
		//sortlist(&s_env);
		//parsing(str, token);
	   // count_init( &token);
		
		//env_cmd(s_env);
		printf("\033[0;36m");
	free(str);
		printf("smt\n");
	}
	return (0);
}
