#include "minishell.h"

int ft_count_tokens(char **token)
{
	int i;

	i = 0;
	while (token[i])
		i++;
	return (i);
}

int count_hrd(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (*str &&  str[0][i])
	{
		if (str[0][i] == '\'')
				i = find_end_of_single_quote(*str, i);
		else if (str[0][i] == '\"')
				i = find_end_of_double_quote(*str, i);
		if (str[0][i] == '<' && str[0][i + 1] && str[0][i + 1] == '<')
		count++;
		i++;
	}
	return (count);
}
t_redirects *new_t_redirects(int flag, char *del, char *pathname)
{
	t_redirects *new_red;

	new_red = malloc(sizeof(t_redirects));
	new_red->flag = flag;
	new_red->del = del;
	new_red->pathname = pathname;
	return (new_red);
}

void	t_redirects_add_back(t_redirects **head, t_redirects *new_node)
{
	t_redirects	*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = new_node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

t_tokens	*new_t_tokens(char *rdl, char **cmd, int *hrd_count)
{
	t_tokens	*new_node;
(void)cmd;
	new_node = malloc(sizeof(t_tokens));;
	new_node->rdl = rdl;
	new_node->cmd = malloc(sizeof(char **));
	new_node->hrd_count = hrd_count;
	//printf("hrd = %d\n", (*new_node->hrd_count));
	new_node->head_redct = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	t_tokens_add_back(t_tokens **head, t_tokens *new_node)
{
	t_tokens	*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = new_node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}


void fill_t_token(t_tokens **token ,char **tokenized, int *hrd_c)
{
	int i;

	i = 0;
	while (tokenized[i])
	{
		t_tokens_add_back(token, new_t_tokens(tokenized[i], NULL, hrd_c));
		i++;
	}
}

int	ft_count_pipe(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
        if (str[i] == '\'')
		    i = find_end_of_single_quote(str, i);
	    else if (str[i] == '\"')
		    i = find_end_of_double_quote(str, i);
		if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}
int check_error(char **tokenized,char *str)
{
	int		count_pipe;
	int		count_tokens;

	count_pipe = ft_count_pipe(str);
	count_tokens = ft_count_tokens(tokenized);
	if (count_pipe && count_tokens - 1 != count_pipe )
	{
		write(2, "Minishell: syntax error near unexpected token `|'\n", 50);
		return (1);
	}
return (0);
}
void 	tokenization(t_tokens **token, char **str)
{
	char	**tokenized;
	int		*hrd_c;

	hrd_c = 0;
	hrd_c = malloc(sizeof(int));
	*hrd_c = count_hrd(str);
	tokenized = smart_split(str[0], '|');
	check_error(tokenized, str[0]);
	fill_t_token(token, tokenized, hrd_c);
	smart_smart_split(token);
	while (*token)
	{
		if ((*token)->rdl) 
		printf("tok = %s\n", (*token)->rdl);
		*token = (*token)->next;
		//printf("tok = %s\n", (*token)->rdl);
//free(hrd_c);
	}
}