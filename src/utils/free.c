
#include "minishell.h"

void	matrix_free(char **env_split)
{
	int	j;

	j = 0;
	while (env_split[j])
	{
		free(env_split[j]);
		j++;
	}
	free(env_split);
}
