#include "minishell.h"

// void	run_cmd(char **str, t_env **l_env)
// {
// 	if (ft_strcmp1(str[0], "pwd"))
// 		pwd_cmd();
// 	if (ft_strcmp1(str[0], "env"))
// 		env_cmd(t_env *env)
// 	if (ft_strcmp1(str[0], "export") && !str[1])
// 		only_export(l_env);
// 	if (ft_strcmp1(str[0], "export"))
// 		export_cmd(l_env, str);
// 	if (ft_strcmp1(str[0], "cd"))
// 		cd_cmd(l_env, str)
// 	if (ft_strcmp(str[0], "echo"))
// 		echo_cmd(str)
// 	if (ft_strcmp1(str[0], "unset"))
// 		unset_cmd(t_env **l_env,char *new_key);
// }

void running(t_tokens **tk, t_env **l_env)
{
(void)l_env;
t_env *env;
t_tokens *token;
token =*tk;
env = *l_env;
(void) env;


while (token)
{
	while (token->head_redct)
	{
		if (token->head_redct && token->head_redct->flag == 2)
		{
			heredoc(token->head_redct->del);
			
		}
		if(token->head_redct->next)
			token->head_redct = token->head_redct->next;
		else
			 break;
	}
	if(token->next)
		token=token->next;
	else 
		break;
}

token = *tk;
	while (token)
	{	
		//printf("cmd = %s\n\n", token->cmd[0]);
         if(token->cmd)
        {
			if (ft_strcmp(token->cmd[0], "exit"))
				exit_cmd(token->cmd);
			if (ft_strcmp(token->cmd[0], "pwd"))
				pwd_cmd();
			if (ft_strcmp(token->cmd[0], "env"))
				env_cmd(env);
			if (ft_strcmp(token->cmd[0], "export") && !token->cmd[1])
				only_export(l_env);
			if (ft_strcmp(token->cmd[0], "export"))
				export_cmd(l_env,token->cmd[1]);
			if (ft_strcmp(token->cmd[0], "cd"))
				cd_cmd(l_env, token->cmd);
			if (ft_strcmp(token->cmd[0], "echo"))
				echo_cmd(token->cmd);
			if (ft_strcmp(token->cmd[0], "unset"))
				unset_cmd(l_env, token->cmd[1]);
			//else execve_cmd(l_env, token->cmd);               
           }
		token=token->next;
	}
	// token = *tk;
}