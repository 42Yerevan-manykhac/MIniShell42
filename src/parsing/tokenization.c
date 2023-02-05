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
void fill_t_token(t_tokens **token,char **tokenized, int *hrd_c)
{
	int i;
	t_tokens *tk;
printf("baba\n");
	i = 0;
	tk = *token;
	while (tokenized[i])
	{
		tk->rdl = tokenized[i];
			printf("token = %s\n", tokenized[i]);
		tk->hrd_count = hrd_c;
		tk->cmd =  (char **)malloc(sizeof(char *));
		tk->head_redct = malloc(sizeof(t_redirects));
		tk->next = NULL;
		if (tokenized[i + 1])
		{
			printf("from fill t_token\n");

			tk->next = malloc(sizeof(t_tokens));
			tk = tk->next;
		//	tk->next = NULL;
			i++;
		}
		else 
			break;
	}
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
	printf("stex\n");
	fill_t_token(token, tokenized, hrd_c);
	printf("mi ban \n");
	smart_smart_split(token);
	// while ((*token))
	// {
	// 	printf("tok = %s\n", (*token)->rdl);
	// 	(*token) = (*token)->next;
	// 	//printf("tok = %s\n", (*token)->rdl);

	// }
}