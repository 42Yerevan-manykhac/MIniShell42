#include "minishell.h"

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

void 	tokenization(t_tokens **token, char **tokenized, char **str )
{
	int	count_pipe;
	(void)token;
    (void)count_pipe;
	count_pipe = ft_count_pipe(str);
	(void) tokenized;
    printf("smt = %d\n", count_pipe);
	tokenized = smart_split(str[0], '|');
	
	int i = 0;
	while(tokenized[i])
	{
		printf("tokenized=> %s\n", tokenized[i]);
		i++;
	}
}