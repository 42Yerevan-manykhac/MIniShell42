#include "minishell.h"
t_env *get_env(t_env **l_env, char *new_key)
{
	t_env *env;

	env = *l_env;
	while (env)
	{
		if (ft_strcmp(new_key ,env->key))
			env = env->next;
		else
			return (env);
	}
	return (0);
}
int find_key(t_env **l_env, char *new_key)
{
	t_env *env;

	env = *l_env;
	while (env)
	{
		printf("new key == %s  env_key = %s\n", new_key, env->key);
		if (ft_strcmp1(new_key ,env->key) != 0)
		{
			printf("xexe\n");
			env = env->next;
		}
		else
		{
			printf("xexe12\n");
			return (1);
		}
	}
	return (0);
}

int if_key_already_exist(t_env **l_env, char **splited)
{
	//printf("splited[0] = %s\n", splited[0]);
	t_env	*rtv;

	rtv = 0;
	if (find_key(l_env, splited[0]))
	{
		printf("find_key\n");
		rtv = get_env(l_env, splited[0]);
		if (rtv->value)
		{
			free(rtv->value);
			rtv->value = splited[1];
		}
		else
		{
			rtv->value = splited[1];
			rtv->next = NULL;
		}
		return (1);
	}
	return (0);
}


void export_cmd(t_env **l_env, char *str)
{
	char **splited;
	t_env *env;
	//	t_env	*tmp;

	env = malloc(sizeof(t_env));
	splited = split_export(str);
	env->key = splited[0];
	//printf("SPL	= %s\n",splited[0] );
	if (!if_key_already_exist(l_env, splited))
	{
		printf("key kaa\n");
		//printf("key ne kaa\n");
	if (splited[1])
		env->value = ft_strdup(splited[1]);
	else
		env->value = 0;
	env->next = NULL;
	ft_lstadd_back(l_env, env);
	}
}

void only_export(t_env **node)
{
	t_env *curr;

	curr = (*node);
	while (curr)
	{
		printf("declare -x %s", curr->key);
		if (curr->value)
			printf("=\"%s\"\n", curr->value);
		else
			printf("\n");
		curr = curr->next;
	}
}
// export a=54 b=65 c=46
// export a
// export a=
// export a=env=env=env=env=env
// export a+=2
// errornery export a!#$%%^&=54, 34567asad=54, a++=54

// env)a export um pahume - a  (chi tpvum env um) eshutyun1 a
// 2)a= export um pahuma - a="" (tpvuma env um a=) eshutyun2
// bayc ete anum es 2 heto env mnuma a="" eshutyun3

// note
// aveli lava split anenq yst havasari heto nayeny valuenery u key eryyyy