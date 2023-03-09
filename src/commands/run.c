#include "minishell.h"

t_count *count_all(t_tokens **tk)
{	
	// printf("-----%s\n", (*tk)->next->head_redct->next->del);
	t_count	*count;
	t_tokens *token;
	token = *tk;
	t_redirects *red1;
	
	count = malloc(sizeof(t_count));
	count->count_1 = 0;
	count->count_3 = 0;
	count->count_4 = 0;
	count->count_herdoc = 0;
while (token)
	{
	red1 = token->head_redct;
		while (token->head_redct->flag)
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
		token->head_redct = red1;
		if(token->next)
			token=token->next;
		else 
			break;
	}
	//printf("-------%d\n", count->count_3);
	return (count);
}

t_count *count_red(t_tokens **tk)
{
t_count	*count;
	t_tokens *token;
	token = *tk;
	t_redirects *red1;
	
	count = malloc(sizeof(t_count));
	count->count_1 = 0;
	count->count_3 = 0;
	count->count_4 = 0;
	count->count_herdoc = 0;

	red1 = token->head_redct;
		while (token->head_redct->flag)
		{
			if (token->head_redct->flag == 1)
				count->count_1++;
			if (token->head_redct->flag == 3)
				count->count_3++;
			if (token->head_redct->flag == 4)
				count->count_4++;
			if (token->head_redct->next)
				token->head_redct = token->head_redct->next;
			else
				break;
		}
		token->head_redct = red1;
	
	//printf("-------%d\n", count->count_3);
	return (count);
}


void do_the_job(t_redirects *token, t_count *len)
{

	if (token->flag == 1)
	{
		if (len->count_1 == 1)
			redirection_input(token->del, 1);
		else
			redirection_input(token->del, 0);
		len->count_1--;
	}
	if (token->flag == 3)
	{
		if (len->count_3 == 1)
		{
	printf("------%d\n", len->count_3);
			redirection_output(token->del, 1);
		}
		else 
			redirection_output(token->del, 0);
		len->count_3--;
	}
	if (token->flag == 4)
	{
		if (len->count_3 == 1)
			redirection_output_append(token->del, 1);
		else 
			redirection_output_append(token->del, 0);
		len->count_4--;
	}	
}

void call_heredoc(t_tokens **tk, int len)
{
	t_tokens *token;
	token =*tk;
	t_redirects *red;

	(void)len;
while (token)
	{

	red = token->head_redct;
		while (token->head_redct)
		{
			if (token->head_redct && token->head_redct->flag == 2)
			{	
				if (len == 1)
					heredoc(token->head_redct->del, 1);
				else 
					heredoc(token->head_redct->del, 0);
				len--;
			}
			if (token->head_redct->next)
				token->head_redct = token->head_redct->next;
			else
				break;
		}

	token->head_redct =red;
	if(token->next)
			token=token->next;
		else 
			break;
}
	token = (*tk);
}

void call_redirections(t_tokens **tk, t_count *len) //hertakanna
{

	t_redirects *red;
	t_tokens	*token;
	// 	int    in_copy;
	// int    out_copy;
	int			i;
	token = *tk;
	i = 1;
	// in_copy = dup(0);
	// out_copy = dup(1);
	while (token)
	{
	 	len  =  count_red((tk));


		red = token->head_redct;
		while (token->head_redct && token->head_redct->flag)
		{
			do_the_job(token->head_redct, len);
	
			if (token->head_redct->next)
				token->head_redct = token->head_redct->next;
			else
				break;
			i++;
		}

			token->head_redct =red;
	if(token->next)
			token=token->next;
		else 
			break;
			free(len);
			// dup2(in_copy, 0);
			// dup2(out_copy, 1);
}
	token = (*tk);
}

void  running(t_tokens **tk, t_env **l_env)
{
	t_env		*env;
	t_tokens	*token;
	t_count		*all_count;

	env = *l_env;
	token = *tk;
	all_count = NULL;
	all_count = count_all(&token);
	token = *tk;

	call_heredoc(tk , all_count->count_herdoc);
	call_redirections(tk, all_count);

	if (token->cmd && token->cmd[0])
	{
		if (ft_strcmp1(token->cmd[0], "exit") == 0)
			exit_cmd(token->cmd);
		else if (ft_strcmp1(token->cmd[0], "pwd") == 0)
			pwd_cmd(l_env);
		else if (ft_strcmp1(token->cmd[0], "env") == 0)
			env_cmd(env);
		else if (ft_strcmp1(token->cmd[0], "export") == 0 && !token->cmd[1])
			only_export(l_env);
		else if (ft_strcmp1(token->cmd[0], "export") == 0)
			export_cmd(l_env, token->cmd[1]);
		else if (ft_strcmp1(token->cmd[0], "cd") == 0)
			cd_cmd(l_env, token->cmd);
		else if (ft_strcmp1(token->cmd[0], "echo") == 0)
			echo_cmd(token->cmd);
		else if (ft_strcmp1(token->cmd[0], "unset") == 0)
			unset_cmd(l_env, token->cmd[1]);
		else
			execve_cmd(l_env, token->cmd);
	}

	free(all_count);
}

void running_p(t_tokens **token, t_env **l_env, int (*fd)[2], int i) // hertakan
{
	
	t_env		*env;
	t_tokens	*tk;

	env = *l_env;
	tk = *token;

	child_pr(fd, i, (*token)->token_count);	
	if ((*token)->cmd && (*token)->cmd[0])
	{
		if (ft_strcmp1((*token)->cmd[0], "exit") == 0)
			exit_cmd((*token)->cmd);
		else if (ft_strcmp1((*token)->cmd[0], "pwd") == 0)
			pwd_cmd(l_env);
		else if (ft_strcmp1((*token)->cmd[0], "env") == 0)
			env_cmd(env);
		else if (ft_strcmp1((*token)->cmd[0], "export") == 0 && !(*token)->cmd[1])
			only_export(l_env);
		else if (ft_strcmp1((*token)->cmd[0], "export") == 0)
			export_cmd(l_env, (*token)->cmd[1]);
		else if (ft_strcmp1((*token)->cmd[0], "cd") == 0)
			cd_cmd(l_env, (*token)->cmd);
		else if (ft_strcmp1((*token)->cmd[0], "echo") == 0)
			echo_cmd((*token)->cmd);
		else if (ft_strcmp1((*token)->cmd[0], "unset") == 0)
			unset_cmd(l_env, (*token)->cmd[1]);
		else
		{
				execve_cmd2(l_env, (*token)->cmd);
		}
	}	
}