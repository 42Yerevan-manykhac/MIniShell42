#include "minishell.h"

void initializer(t_tokens **token)
{
	t_tokens *node;

	node = *token;
	node->count.count_cmd = 0;
	node->count.count_herdoc = 0;
	node->count.count_redirect = 0;
}

void malloc_init(t_tokens **token)
{
	t_tokens *node;

	node = *token;
	node->cmd = (char **)malloc(sizeof(char *) * (node->count.count_cmd + 1));
	node->herdoc = (char **)malloc(sizeof(char *) 
								* (node->count.count_herdoc + 1));
	node->redirect = (char **)malloc(sizeof(char *) * (node->count.count_redirect + 1));
	node->cmd[node->count.count_cmd] = 0;
	node->herdoc[node->count.count_herdoc] = 0;
	node->redirect[node->count.count_redirect] = 0;
}

int	pars_s(t_tokens **token, int i, int c, int index)
{
	int j;
	t_tokens *node;
	node = *token;

	j = 0;
	i++;
	while (node->rdl[i] == ' ')
		i++;
	j = i;
	while (!ft_strchr(METACHARS, node->rdl[i]))
			i++;
	if (index == 1)
		node->redirect[c] = ft_strjoin("<", ft_substr(node->rdl, j, i - j));
	else if(index == 2)
		node->herdoc[c] = ft_strjoin("<<", ft_substr(node->rdl, j, i - j));
	else if (index == 3)
		node->redirect[c] = ft_strjoin(">", ft_substr(node->rdl, j, i - j));
		else if (index == 4)
		node->redirect[c] = ft_strjoin(">>", ft_substr(node->rdl, j, i - j));
	return (i);
}

int c_comand(t_tokens **token, int i, int c_c)
{
	int j;

	j = 0;
	while ((*token)->rdl[i] == ' ')
				i++;
		j = i;
	while ((*token)->rdl[i] && !ft_strchr(METACHARS, (*token)->rdl[i]))
			i++;
	(*token)->cmd[c_c] = ft_substr((*token)->rdl, j, i - j);
			c_c++;
	return (i);
}

void parsing(char *str, t_tokens **token)
{
	int i;
	int c_r;
	int c_c;
	int c_h;

	i = 0;
	c_r = 0;
	c_c = 0;
	c_h = 0;
	malloc_init(token);
	while ((*token)->rdl && (*token)->rdl[i])
	{
		if (str[i] == '<' && str[i + 1] != '<') /////111
			i = pars_s(token, i, c_r++ , 1);
		else if (str[i] == '<' && str[i + 1] == '<') /// 2
			i = pars_s(token, ++i,c_h++ , 2);
		else if (str[i] == '>' && str[i + 1] != '>')
			i = pars_s(token, i,c_r++ , 3);
		else if (str[i] == '>' && str[i + 1] == '>')
			i = pars_s(token, ++i,c_r++ , 4);
		else if (str[i] == ' ')
			i++;
		else
			i = c_comand(token, i, c_c++);
	}
}





