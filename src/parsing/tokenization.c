#include "minishell.h"

int ft_count_tokens(char **token)
{
	int i;
<<<<<<< HEAD
	i = 0;
	while (token[i])
		i++;
	return (i);
=======

	i = 0;
	while (token[i])
		i++;
	return (0);
>>>>>>> d11407443d959095b2350a28eed3a90710151cd1
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
		if (tokenized[i + 1])
			tk->next = malloc(sizeof(t_tokens));
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
	int		count_tokens;
	char	**tokenized;
	int		*hrd_c;
<<<<<<< HEAD
	
=======
	(void)count_pipe;
>>>>>>> d11407443d959095b2350a28eed3a90710151cd1
	hrd_c = 0;
	count_pipe = ft_count_pipe(str);
	hrd_c = malloc(sizeof(int));
	*hrd_c = count_hrd(str);
	tokenized = smart_split(str[0], '|');
<<<<<<< HEAD
	count_tokens = ft_count_tokens(tokenized);
	fill_t_token(token, tokenized, hrd_c);
=======
	fill_t_token(token, tokenized, hrd_c);
	
>>>>>>> d11407443d959095b2350a28eed3a90710151cd1
}