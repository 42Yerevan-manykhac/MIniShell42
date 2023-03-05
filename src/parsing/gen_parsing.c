#include "minishell.h"

int	check(int i, char *str, int *flg)
{
	if (str[i] == '\'')
		i = find_end_of_single_quote(str, i);
	else if (str[i] == '\"')
		i = find_end_of_double_quote(str, i);
	else if (str[i] && str[i] == '<')
	{
		if(!str[i + 1])
			*flg = 0;
		else if( str[i + 1] && str[i + 1] != '<' )
		{
			i++;
			if (cheack_back(str, i - 1) || cheack_front(str, &i))
			{
				*flg = 0;
			}
		}
		else if (str[i + 1]  && str[i + 1] == '<')
		{
			i += 2;
			if (cheack_front(str, &i))
				*flg = 0;
		}
	}
	else if (str[i] && str[i] == '>')
	{
		if(!str[i + 1] )
			*flg = 0;
		else if ( str[i + 1] && str[i + 1] != '>')
		{
			i++;
			if (cheack_front(str, &i))
				*flg = 0;
		}
		else if (str[i + 1] && str[i + 1] == '>')
		{
			i += 2;
			if (cheack_front(str, &i))
				*flg = 0;
		}
	}
	return (i);
}


int	syntax_pars_2(char *str)
{
	int	i;
	int	flg;

	flg = 1;
	i = 0;
	while (str[i])
	{
		i = check(i, str, &flg);
		if (!flg)
			break;
		i++;
	}
	if (flg == 0)
	{
		print_error(NULL, "syntax error near unexpected token `newline", 258);
		return (1);
	}
	return (0);
}


int	syntax_pars_1(char c)
{
	if (c == '|' || c == '&' || c == ';')
	{
		exit_code = 2;
		print_error(NULL, "syntax error near unexpected token `newline", 258);
		return (1);
	}
	return (0);
}

int	syntax_pars(char **str)
{
	if (syntax_pars_1(*str[0]))
		return (1);
	if (syntax_pars_2(*str))
		return (1);
	return (0);
}

int		gen_parsing(t_tokens **token, t_env **env, char **str)
{
	char	*tmp;
	(void)env;
	(void)str;
	(void)token;

t_tokens *tk;

tk = *token;
	tmp = *str;
	*str = ft_strtrim(tmp, " ");
	free(tmp);
	if (syntax_pars(str))
		return (1);
	// printf(",,%s\n", *str);
    dolar_pars(str, env);
	interrogatory(str);		
	tokenization(token, str);
	// printf("AYO\n");
	return (0);
}
