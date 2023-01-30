
#include "minishell.h"

int	main(int arg_nb, char **argv, char **env)
{
	(void)arg_nb;
	(void)argv;
	char		*str;
	int    in_copy;
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
		in_copy = dup(0);
		str = readline ("Minishell$> ");
		printf("\033[0;35m");
		if (str)
			add_history(str);
		//export_cmd(&s_env,str); //(done( check only_export ))//++ done
		//env_cmd(s_env);
	//	only_export(&s_env);
	//heredoc(str); //++done
		//unset_cmd(&s_env, str);  // done
		//redirection_input(str, 1);
		//export_no_args(&s_env);    ///anel stugel krkin nayel 
		//pwd_cmd();
		//cd_cmd(&s_env, &str);
		gen_parsing(&token, &s_env, &str);
		printf("str ==> %s\n", str);
	dup2(in_copy, 0);
		//parsing(str, token);
	   // count_init( &token);
		
		//env_cmd(s_env);
		printf("\033[0;36m");  
	free(str);
	}
	return (0);
}
