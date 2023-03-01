#include "minishell.h"

void	pwd_cmd(t_env **l_env)
{
	//char	cwd[256];
	//t_env	*env;
	t_env	*tmp;


	//env = *t_env;
	tmp = get_env(l_env, "PWD");
	printf("%s\n", tmp->value);
	
}

void	env_cmd(t_env *env)
{
	while (env)
	{
		if (env && env->flag)
		{
			//if (env->flag)
			//{
				printf("%s", env->key);
				printf("=");
				if (env->value)
					printf("%s\n", env->value);
				else
					printf("\n");
			//}
		}
		env = env->next;
	}
}