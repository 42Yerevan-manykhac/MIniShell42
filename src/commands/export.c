#include "minishell.h"

void	export_cmd(t_env **l_env,char *str, int i)
{
	int		x;
	t_env	*env;

	env = malloc(sizeof(t_env));
	x = i;
	while (str[i] != '=')
		i++;
	env->key = ft_substr(str, x, i - 1);
	while (str[i] != ' ')
		i++;
	env->value = ft_substr(str, x, i - 1);
	ft_lstadd_back(l_env, env);
}
//export a=54 b=65 c=46
//export a
//export a=
//export a=1=1=1=1=1
//export a+=2
//errornery export a!#$%%^&=54, 34567asad=54, a++=54



//note
//aveli lava split anenq yst havasari heto nayeny valuenery u key eryyyy