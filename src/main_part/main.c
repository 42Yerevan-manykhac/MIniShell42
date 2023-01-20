
#include "minishell.h"

int	main(int arg_nb, char **argv, char **env)
{
	(void)arg_nb;
	(void)argv;
	// (void)env;
	char		*str;
	t_tokens	*token;
	t_env		*s_env;
	(void)s_env;
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
		//gen_parsing(&token, &s_env, str);
		//printf("\n\nstr = %s\n\n", str);
		//unset_cmd(&s_env, str);
		env_cmd(s_env);
		//export_cmd(&s_env,str); (done( check only_export ))
		 
		 
		printf("\033[0;36m");
		//sortlist(&s_env);
		//parsing(str, token);
	   // count_init( &token);
		
		//env_cmd(s_env);
	// 	printf("count_redirect-%d\n", token->count.count_redirect );
	// 	printf("count_cmd-%d\n", token->count.count_cmd );
	// 	printf("count_herdoc-%d\n", token->count.count_herdoc );
	// 	int i = 0;
		
	// 	while (i < token->count.count_cmd)
	// 	{
	// 		printf("cmd[%d]!%s!\n", i, token->cmd[i]);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	while (i < token->count.count_redirect)
	// 	{
	// 		printf("redirect[%d]!%s!\n", i, token->redirect[i]);
	// 		i++;
	// 	}
	// 		 i = 0;
	// 	while (i < token->count.count_herdoc)
	// 	{
	// 		printf("herdoc[%d]!%s!\n", i, token->herdoc[i]);
	// 		i++;
	// 	}
	//////free(str);
	}
	return (0);
}
