#include "minishell.h"

void	export_cmd(t_env **l_env, char *str)
{
	char	**splited;
	t_env	*env;

	env = malloc(sizeof(t_env));
	splited = split_export(str);
	env->key = splited[0];
	env->value = splited[1];
	env->next = NULL;
	ft_lstadd_back(l_env, env);
}
//export a=54 b=65 c=46
//export a
//export a=
//export a=1=1=1=1=1
//export a+=2
//errornery export a!#$%%^&=54, 34567asad=54, a++=54

//1)a export um pahume - a  (chi tpvum env um) eshutyun1 a
//2)a= export um pahuma - a="" (tpvuma env um a=) eshutyun2
//bayc ete anum es 2 heto 1 mnuma a="" eshutyun3

//note
//aveli lava split anenq yst havasari heto nayeny valuenery u key eryyyy