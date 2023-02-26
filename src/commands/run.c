#include "minishell.h"

t_count *count_all(t_tokens **tk)
{	
	t_count	*count;
	t_tokens *token;
	token =*tk;

	count = malloc(sizeof(t_count));
	count->count_1 = 0;
	count->count_3 = 0;
	count->count_4 = 0;
	count->count_herdoc = 0;
	while (token)
	{
		while (token->head_redct)
		{
			if (token->head_redct->flag == 1)
				count->count_1++;
			if (token->head_redct->flag == 2)
				count->count_herdoc++;
			if (token->head_redct->flag == 3)
				count->count_3++;
			if (token->head_redct->flag == 4)
				count->count_4++;
			if (token->head_redct->next)
				token->head_redct = token->head_redct->next;
			else
				break;
		}
		if(token->next)
			token=token->next;
		else 
			break;
	}
	return (count);
}


void call_heredoc(t_tokens **tk, int len)
{
	t_tokens *token;
	token =*tk;

	(void)len;
	while (token)
	{
		while (token->head_redct)
		{
			if (token->head_redct && token->head_redct->flag == 2)
			{
				heredoc(token->head_redct->del, 0);
			}
			if (token->head_redct->next)
				token->head_redct = token->head_redct->next;
			else
				break;
		}
		if(token->next)
			token=token->next;
		else 
			break;
	}
}

void call_redirections(t_tokens **tk, t_count *len)
{
	t_tokens	*token;
	int			i;
	token = *tk;
	printf("len = %d\n", len->count_1);
	while (token)
	{
		while (token->head_redct)
			{
				if (token->head_redct->flag == 1)
					redirection_input(token->head_redct->del, 1);
				if (token->head_redct->flag == 3)
					redirection_output(token->head_redct->del, 1);
				if (token->head_redct->flag == 4)
					redirection_output_append(token->head_redct->del, 1);
				if (token->head_redct->next)
				token->head_redct = token->head_redct->next;
				else
					break;
				i++;
			}
			if (token->next)
				token=token->next;
			else 
				break;
	}
}

void running(t_tokens **tk, t_env **l_env)
{
	t_env		*env;
	t_tokens	*token;
	t_count		*all_count;
	env = *l_env;
	token = *tk;

	all_count = NULL;
	all_count = count_all(tk);
	call_heredoc(tk , all_count->count_herdoc);
	call_redirections(tk, all_count);
	while (token)
	{
		if (token->cmd && token->cmd[0])
		{
			if (ft_strcmp(token->cmd[0], "exit"))
				exit_cmd(token->cmd);
			else if (ft_strcmp(token->cmd[0], "pwd"))
				pwd_cmd();
			else if (ft_strcmp(token->cmd[0], "env"))
				env_cmd(env);
			else if (ft_strcmp(token->cmd[0], "export") && !token->cmd[1])
				only_export(l_env);
			else if (ft_strcmp(token->cmd[0], "export"))
				export_cmd(l_env, token->cmd[1]);
			else if (ft_strcmp(token->cmd[0], "cd"))
				cd_cmd(l_env, token->cmd);
			else if (ft_strcmp(token->cmd[0], "echo"))
				echo_cmd(token->cmd);
			else if (ft_strcmp(token->cmd[0], "unset"))
				unset_cmd(l_env, token->cmd[1]);
			else 
				execve_cmd(l_env, token->cmd);
		}
		else
		   	if (!token->cmd || (token->cmd && !token->cmd[0]))
			{
				//print_error("", "command not found", 127);
				return ;
			} 
			token=token->next;
	}
	// token = *tk;
}


