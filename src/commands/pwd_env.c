#include "minishell.h"

void	pwd_cmd(t_env **l_env)
{
	t_env	*tmp;

	tmp = get_env(l_env, "PWD");
	if (tmp == NULL)
		print_error("PWD", "No such file or directory", 127);
	else
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