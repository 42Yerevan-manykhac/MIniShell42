#include "minishell.h"
void cat_the_spaces(t_tokens **token)
{
	int 	i;
	//int		j;
	t_tokens *tok;

	i = 0;
//	j = 0;
	tok = *token;
	printf("tok = %s\n", tok->rdl);
	while (tok)
	{
		while (tok->rdl[i])
		{
			if (tok->rdl[i] == '<' && tok->rdl[i + 1] == '<')
				
			printf("str[i] = %c\n",tok->rdl[i] );
			i++;
		}
		i = 0; 
		tok = tok->next;
	}
}

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
void fill_t_token(t_tokens **token,char **tokenized, int *hrd_c)
{
	int i;
	t_tokens *tk;

	i = 0;
	tk = *token;
	while (tokenized[i])
	{
		tk->rdl = tokenized[i];
		tk->hrd_count = hrd_c;
			printf("smt = %d\n", i);
		if (tokenized[i + 1])
		{
			tk->next = malloc(sizeof(t_tokens));
			tk = tk->next;
			tk->next = NULL;
			i++;
		}
		else 
			break;
		//tk = tk->next;
		//i++;
	}
	//tk->next = NULL;
}

int	ft_count_pipe(char **str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[0][i])
	{
        if (str[0][i] == '\'')
		    i = find_end_of_single_quote(*str, i);
	    else if (str[0][i] == '\"')
		    i = find_end_of_double_quote(*str, i);
		if (str[0][i] == '|')
			count++;
		i++;
	}
	return (count);
}

void 	tokenization(t_tokens **token, char **str )
{
	//int		count_pipe;
	//int		count_tokens;
	char	**tokenized;
	int		*hrd_c;	

	hrd_c = 0;
	//count_pipe = ft_count_pipe(str);
	hrd_c = malloc(sizeof(int));
	*hrd_c = count_hrd(str);
	tokenized = smart_split(str[0], '|');
	//count_tokens = ft_count_tokens(tokenized);
	fill_t_token(token, tokenized, hrd_c);
	// while ((*token))
	// {
	// 	printf("mi ban\n");
	// 	printf("tok = %s\n", (*token)->rdl);
	// 	(*token) = (*token)->next;
	// }
	cat_the_spaces(token);
}