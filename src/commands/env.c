#include "minishell.h"

void	env_init(char **env, t_env **s_env)
{
	int		i;
	char	**env_split;

	i = 0;
	while (env[i])
	{
		env_split = ft_split(env[i], '=');
		(*s_env)->key = env_split[0];
		(*s_env)->value = env_split[1];
		free(env_split);
		if (ft_strcmp((*s_env)->key, "OLDPWD"))
			(*s_env)->flag = 0;
		else
			(*s_env)->flag = 1;
		(*s_env)->next = NULL;
		if (env[i + 1])
		{
			(*s_env)->next = malloc(sizeof(t_env));
			s_env = &(*s_env)->next;
		}
		i++;
	}
	(*s_env)->next = NULL;
}
