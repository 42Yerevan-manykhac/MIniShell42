#include "minishell.h"

void	pwd_cmd(void)
{
	char	cwd[256];

	printf("%s\n", getcwd(cwd, sizeof(cwd)));
}

void	env_cmd(t_env *env)
{
	while (env)
	{
		if (env && env->flag)
		{
			printf("%s", env->key);
			printf("=");
			if (env->value)
				printf("%s\n", env->value);
			else
				printf("\n");
		}
		env = env->next;
	}
}