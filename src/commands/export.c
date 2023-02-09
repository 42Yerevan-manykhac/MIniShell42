#include "minishell.h"

t_env	*get_env(t_env **l_env, char *new_key)
{
	t_env	*env;

	env = *l_env;
	while (env)
	{
		if (ft_strcmp1(new_key, env->key))
			env = env->next;
		else
			return (env);
	}
	return (0);
}

int	if_need_to_add(t_env **l_env, char **splited)
{
	int		len;
	t_env	*rtv;
	char    *tmp;

	rtv = 0;
	len = ft_strlen(splited[0]);
	if (splited[0][len - 1] == '+')
	{
		splited[0] = ft_strtrim(splited[0], "+");
		if (find_key(l_env, splited[0]))
		{
			if (!splited[1])
			{
				free(splited[0]);
				return (1);
			}
			rtv = get_env(l_env, splited[0]);
			free(splited[0]);
			if (!rtv->value)
					rtv->value = splited[1];
			else
			{
				tmp = rtv->value;
				rtv->value = ft_strjoin(tmp, splited[1]);
				free(splited[1]);
				free(tmp);
			}
			return (1);
		}
	}
	return (0);
}

int	find_key(t_env **l_env, char *new_key)
{
	t_env	*env;

	env = *l_env;
	while (env)
	{
		if (ft_strcmp1(new_key, env->key) != 0 && env)
			//printf("env == %s , new_key = %s\n",env->key, new_key);
			env = env->next;
		else
			return (1);
	}
	return (0);
}

int	if_key_already_exist(t_env **l_env, char **splited)
{
	t_env	*rtv;

	rtv = 0;
	if (if_need_to_add(l_env, splited))
		return (1);
	if (find_key(l_env, splited[0]))
	{
		rtv = get_env(l_env, splited[0]);
		if (rtv->value)
		{
			free(rtv->value);
			free(splited[0]);
			rtv->flag = 1;
			rtv->value = splited[1];
		}
		else
		{
			if (splited[1])
			{
				rtv->value = splited[1];
				rtv->flag = 1;
				free(splited[0]);
			}
			else
			{
				free(splited[0]);
				rtv->flag = 1;
			}
			//free(rtv->value);
		}
		return (1);
	}
	return (0);
}

void	export_cmd(t_env **l_env, char *str)
{
	int		i;
	t_env	*env;
	int		len;
	char	**splited;

	len = ft_strlen(str);
	i = ft_int_strchr(str, '=');
	splited = split_export(str);
	if (!if_key_already_exist(l_env, splited))
	{
		env = malloc(sizeof(t_env));
		env->key = splited[0];
		if (splited[1])
		{		
			env->flag = 1;
			env->value = splited[1];
		}
		else if (i && i == len - 1)
		{	
				env->flag = 1;
				env->value = 0;
		}
		else
		{
			env->flag = 0;
			env->value = 0;
		}
		env->next = NULL;
		ft_lstadd_back(l_env, env);
	}
	free(splited);
}

void	only_export(t_env **node)
{
	t_env	*curr;

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



//parsingum nayel key = inchvorban+ kam tiv;**