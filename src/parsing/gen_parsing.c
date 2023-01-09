
#include "minishell.h"

int	check(int i, char *str, int *flg)
{
	if ((str[i] == '<' && str[i + 1] != '<')
		|| (str[i] == '>' && str[i + 1] != '>') || str[i] == '|')
	{
		i++;
		if (cheack_back(str, i - 2) || cheack_front(str, &i))
			*flg = 0;
	}
	else if ((str[i] == '>' && str[i + 1] == '>'))
	{
		i += 2;
		if (cheack_back(str, i - 3) || cheack_front(str, &i))
			*flg = 0;
	}
	else if (str[i] == '<' && str[i + 1] == '<')
	{
		i += 2;
		if (cheack_front(str, &i))
			*flg = 0;
	}
	else
		i++;
	return (i);
}

int	syntax_pars_2(char *str)
{
	int	i;
	int	flg;

	flg = 1;
	i = 0;
	while (str[i])
		i = check(i, str, &flg);
	if (flg == 0)
	{
		write(2, "Minishell: syntax error near unexpected token `newline'\n", 58);
		return (1);
	}
	return (0);
}

int	syntax_pars_1(char c)
{
	if (c == '|' || c == '&' || c == ';')
	{
		write(2, "Minishell: syntax error near unexpected token `", 48);
		write(2, &c, 1);
		write(2, " '\n", 3);
		return (1);
	}
	return (0);
}

int	syntax_pars(t_tokens **token)
{
	t_tokens	*node;

	node = *token;
	if (syntax_pars_1(node->rdl[0]))
		return (1);
	if (syntax_pars_2(node->rdl))
		return (1);
	return (0);
}

int	gen_parsing(t_tokens **token, t_env **env, char *str)
{
	t_tokens	*node;
	(void)env;
	node = *token;
	node->rdl = ft_strtrim(str, " ");
	if (syntax_pars(token))
		return (1);
	dolar_pars(node->rdl, env);
	 	//return (1);
	return (0);
}
