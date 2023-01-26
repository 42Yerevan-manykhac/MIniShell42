#include "minishell.h"

int	pre_parsing(char *str)
{
	int	i;

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
			printf("Minishell: syntax error near unexpected token `<'\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_redirect( t_tokens **token, int i)
{
	t_tokens	*node;

	node = *token;
	node->count.count_redirect++;
	i++;
	while (node->rdl[i] == ' ')
		i++;
	while (!ft_strchr(METACHARS, node->rdl[i]))
		i++;
	return (i);
}

int	check_herdoc( t_tokens **token, int i)
{
	t_tokens	*node;

	node = *token;
	node->count.count_herdoc++;
	i = i + 2;
	while (node->rdl[i] == ' ')
		i++;
	while (!ft_strchr(METACHARS, node->rdl[i]))
		i++;
	return (i);
}

int	check_cmd(t_tokens **token, int i)
{
	t_tokens	*node;

	node = *token;
	while (!ft_strchr(METACHARS, node->rdl[i]))
				i++;
	node->count.count_cmd++;
	while (node->rdl[i] == ' ')
		i++;
	return (i);
}

int	count_init(t_tokens **token)
{
	int			i;
	t_tokens	*node;

	node = *token;
	i = 0;
	initializer(&node);
	// if (pre_parsing(node->rdl))
	// 	return (1);
	while (node->rdl[i] != '\0') 
	{
	//  if(node->rdl[i]=='|')
	// 	{
	// 		node = node->next;
	// 		node->next = NULL;
	// 		i++;
	// 		count_init(&node);
	// 	}
	// else {
	// 	i = 0;
		if ((node->rdl[i] == '<' && node->rdl[i + 1] != '<')
			|| (node->rdl[i] == '>' && node->rdl[i + 1] != '>'))
			i = check_redirect(&node, i);
		else if (node->rdl[i] == '<' && node->rdl[i + 1] == '<')
				i = check_herdoc(&node, i);
		else if (node->rdl[i] == '>' && node->rdl[i + 1] == '>')
			i = check_redirect(&node, ++i);	
		else if (node->rdl[i] == ' ')
			i++;
		else
			i = check_cmd(&node, i);
		}
	//}
	return(0);
}