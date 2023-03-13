
#include "minishell.h"

int exit_code = 0;

void	ctrl_d_check(char *s)
{
	if (!s)
	{
		write(1, "exit\n", 5);
		exit(exit_code);
	}
}

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
	s_env = malloc(sizeof(t_env));
	env_init(env, &s_env);
	shell_level(&s_env);
	while (1)
	{
		sig_control(1);
		in_copy = dup(0);
		out_copy = dup(1);
		str = readline ("Minishell$> ");
		ctrl_d_check(str);
		printf("\033[0;35m");
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
			dup2(in_copy, 0);
			dup2(out_copy, 1);
			close(out_copy);
			printf("\033[0;36m");
			free_t_list(&token);
		}
		free(str);
	}
	return (0);
}
