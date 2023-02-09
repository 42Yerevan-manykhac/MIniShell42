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
	while (token)
	{	
        if(token->cmd[0])
           { 
  
                	if (ft_strcmp(token->cmd[0], "exit"))
                        exit_cmd(token->cmd);
                    if (ft_strcmp(token->cmd[0], "pwd"))
                		pwd_cmd();
                	else if (!ft_strcmp1(token->cmd[0], "env"))
                    {
                      //  printf("\n\nstr -------> %s\n\n",token->cmd[0]);
                		env_cmd(env);
                    }
					// printf("\n\nstr1 -------> %s\n\n",token->cmd[0]);
                	if (ft_strcmp(token->cmd[0], "export") && !token->cmd[1])
                		only_export(l_env);
						// printf("\n\nstr2 -------> %s\n\n",token->cmd[0]);
                	if (ft_strcmp(token->cmd[0], "export"))
                		export_cmd(l_env,token->cmd[1]);
						// printf("\n\nstr3-------> %s\n\n",token->cmd[0]);
                	if (ft_strcmp(token->cmd[0], "cd"))
                		cd_cmd(l_env, token->cmd);
				//	 printf("\n\nstr4 -------> %s\n\n",token->cmd[0]);
                	if (ft_strcmp(token->cmd[0], "echo"))
					{

						 //printf("\n\nstr5 -------> %s\n\n",token->cmd[0]);
                		echo_cmd(token->cmd);
					}
						if (!ft_strcmp1(token->cmd[0], "unset"))
							unset_cmd(l_env, token->cmd[1]);
                                    
           }
		token=token->next;
	}
}