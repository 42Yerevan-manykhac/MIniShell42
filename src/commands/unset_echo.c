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
		one_node_free(&rtv);
	}
}

void	echo_cmd(char **str)
{
	int i;

	i = 0;
	if (ft_strcmp(str[1], "-n"))
	{
		if (str[2])
		{
			i = 2;
			while(ft_strcmp(str[i], "-n"))
					i++;
			while(str[i])
			{
				printf("%s ",str[i]);
					i++;
			}
		}
	}
	else
	{
		if (str[1])
		{
			i = 1;
			while(str[i])
			{
				printf("%s ",str[i]);
				i++;
			}
			printf("\n");
		}
		else printf("\n");
	}
}
//Volodyayi case-ery chnayel
