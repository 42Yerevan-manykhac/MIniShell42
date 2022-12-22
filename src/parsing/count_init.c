#include "minishell.h"

int pre_parsing(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
		{
			printf("Minishell: syntax error near unexpected token `>'\n");
			return (1);
		}
		else if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
		{
			printf("bash: syntax error near unexpected token `<'\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int check_redirect(char *str, t_tokens **token, int i)
{
	t_tokens *node;

	node = *token;
	node->count.count_redirect++;
	i++;
	while (str[i] == ' ')
		i++;
	while (!ft_strchr(METACHARS, str[i]))
		i++;
		return (i);
}

int check_herdoc(char *str, t_tokens **token, int i)
{
	t_tokens *node;

	node = *token;
	node->count.count_herdoc++;
	i = i + 2;
	while (str[i] == ' ')
		i++;
	while (!ft_strchr(METACHARS, str[i]))
		i++;
		return (i);
}


int check_cmd(char *str, t_tokens **token, int i)
{
	t_tokens *node;

	node = *token;
	while (!ft_strchr(METACHARS, str[i]))
				i++;
			node->count.count_cmd++;
			while (str[i] == ' ')
				i++;
				return (i);
}

int count_init(char *str, t_tokens **token)
{
	int i;
	int j;
	t_tokens *node;

	node = *token;
	j = 0;
	i = 0;
	initializer(&node);
	if (pre_parsing(str))
		return (1);
	while (str[i] != '\0') 
	{
		if ((str[i] == '<' && str[i + 1] != '<') 
		|| (str[i] == '>' && str[i + 1] != '>'))
			i = check_redirect(str, &node, i);
		else if (str[i] == '<' && str[i + 1] == '<')
				i = check_herdoc(str, &node,i);
		else if(str[i] == '>' && str[i + 1] == '>')
			i = check_redirect(str, &node,++i);	
		else if (str[i] == ' ')
			i++;
		else
			i = check_cmd(str, &node,i);
	}
	return(0);
}