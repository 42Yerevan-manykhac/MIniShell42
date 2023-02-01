#include "minishell.h"

void fill_t_token(t_tokens **token,char **tokenized)
{
	int i;
	t_tokens *tk;

	i = 0;
	tk = *token;
	while (tokenized[i])
	{
		tk->rdl = tokenized[i];
		if (tokenized[i + 1])
			tk->next = malloc(sizeof(t_tokens));
	printf("token == %s\n", tk->rdl);
		tk = tk->next;
		i++;
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
	int		count_pipe;
	char	**tokenized;
	(void)token;
    (void)count_pipe;
	count_pipe = ft_count_pipe(str);
	(void) tokenized;
    printf("smt = %d\n", count_pipe);
	tokenized = smart_split(str[0], '|');
	fill_t_token(token, tokenized);
	int i = 0;
	while(tokenized[i])
	{
		printf("tokenized=> %s\n", tokenized[i]);
		i++;
	}
}