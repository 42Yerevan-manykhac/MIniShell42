#include "minishell.h"

void shell_level(t_env **env)
{
	t_env	*rtv;
	int		tmp;

	rtv = get_env(env, "SHLVL");
	tmp = ft_atoi(rtv->value);
	free(rtv->value);
	rtv->value = ft_itoa(tmp + 1);
}