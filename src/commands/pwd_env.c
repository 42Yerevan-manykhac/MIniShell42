#include "minishell.h"

void	pwd_cmd(void)
{
	char	cwd[256];

	printf("%s\n", getcwd(cwd, sizeof(cwd)));
}

void env_cmd(t_env *env)
{
	 while (env)
	 {
		printf("%s",env->key);
		printf("=");
		printf("%s\n",env->value);
		env = env->next;
	 }
}