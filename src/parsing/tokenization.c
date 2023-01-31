#include "minishell.h"

#include "minishell.h"

int	ft_count_pipe(char **str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[0][i])
	{
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

	count_pipe = ft_count_pipe(str);
	(void) tokenized;
	tokenized = smart_split(str[0], '|');
	
	int i = 0;
	while(tokenized[i])
	{
		printf("tokenized=> %s\n", tokenized[i]);
		i++;
	}
}