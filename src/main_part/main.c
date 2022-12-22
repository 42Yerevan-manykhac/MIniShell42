
#include "minishell.h"

int	main(int arg_nb, char **argv, char **env)
{
	(void)arg_nb;
	(void)argv;
	(void)env;
	t_tokens *token;
	t_env *s_env;
	

	token = malloc(sizeof(t_tokens));	
	s_env = malloc(sizeof(t_env));
	while (1)
	{
		token->rdl = readline ("Minishell$> ");
	//	parsing(str, token);
		count_init(token->rdl, &token);
		env_init(env, s_env);
		parsing(token->rdl, &token);
		if (token->rdl[0])
			 add_history(token->rdl);
		//env_cmd(s_env);
		printf("count_redirect-%d\n", token->count.count_redirect );
		printf("count_cmd-%d\n", token->count.count_cmd );
		printf("count_herdoc-%d\n", token->count.count_herdoc );
		int i = 0;
		
		while (i < token->count.count_cmd)
		{
			printf("cmd[%d]!%s!\n", i, token->cmd[i]);
			i++;
		}
		i = 0;
		while (i < token->count.count_redirect)
		{
			printf("redirect[%d]!%s!\n", i, token->redirect[i]);
			i++;
		}
			 i = 0;
		while (i < token->count.count_herdoc)
		{
			printf("herdoc[%d]!%s!\n", i, token->herdoc[i]);
			i++;
		}
	}
	return (0);
}
