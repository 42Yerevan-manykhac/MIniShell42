
#include "minishell.h"

void	update_oldpwd(t_env **l_env)
{
	t_env	*env;

	env = get_env(l_env, "OLDPWD");
	free(env->value);
	env->value = ft_strdup(get_env(l_env, "PWD")->value);
}

void	cd_cmd(t_env **l_env, char **str)
{
	update_oldpwd(l_env);
	if ((ft_strcmp1("cd", str[0]) && !str[1]) || ft_strcmp1("cd ~", str[0]))
		chdir(get_env(l_env, "HOME")->value);
	else
		chdir(str[1]);
}

// anumes zut    cd    kam   cd ~   (nuynn en) -- tla homy
// mnacac zut chdir talist enc cd ic hetoi argumentnery 


//getcwd() - 
//chdir();


//update old pwd 
