
#include "minishell.h"

int	syntax_pars_1(char c)
{              
	if (c == '|' || c == '&' || c == ';')
	{
		write(2, "Minishell: syntax error near unexpected token `", 48);
		write(2, &c, 1);
		write(2, "'\n", 2);
		return (1);
	}
	return (0);
}
int syntax_pars(t_tokens **token)
{
	t_tokens	*node;
	int			i;

	i = 0;
	node = *token;
//	while (node->rdl[i])
	//{
		if (syntax_pars_1(node->rdl[0]))
			return (1);
//	i++
//	}
	return (0);
}
int	gen_parsing(t_tokens **token, char *str)
{
	t_tokens *node;

	node = *token;
	node->rdl = ft_strtrim(str, " ");
	if (syntax_pars(token))
		return (1);
	printf("\nstr == %s\n", node->rdl);
	return (0);
}