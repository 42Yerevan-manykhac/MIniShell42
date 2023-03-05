#include "minishell.h"

int	env_len(t_env **l_env)
{
	t_env	*env;
	int		count;

	count = 0;
	env = *l_env;
	while (env)
	{
		env = env->next;
		count++;
	}
	return (count);
}

int	matrix_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}