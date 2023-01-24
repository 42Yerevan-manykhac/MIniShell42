#include "minishell.h"

void	unset_cmd(t_env **l_env, char *new_key)
{
	t_env	*env;
	t_env	*rtv;

	env = *l_env;
	rtv = 0;
	if (find_key(l_env, new_key))
	{
		rtv = get_env(l_env, new_key);
		while (env->next != rtv)
			env = env->next;
		env->next = rtv->next;
		free(rtv);
	}
}

void	echo_cmd(char **str)
{
	if (ft_strcmp1(str[1],"-n") == 0)
		printf("%s",str[2]);
	else 
		printf("%s\n",str[2]);
}
//Volodyayi case-ery chnayel