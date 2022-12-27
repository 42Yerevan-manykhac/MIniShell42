
#include "minishell.h"

int	cheack_front(char *str, int *x)
{
	int	i;

	i = *x;
	while (str[*x] == ' ')
			(*x)++;
	while (!ft_strchr(METACHARS, str[*x]))
		(*x)++;
		//printf(" i = %d, x = %d\n",i , *x );
	if (*x - i - 1 <= 0)
		return (1);
	return (0);
}

int	cheack_back(char *str, int x)
{
	int i;
	while (str[x] == ' ')
			x--;
	i = x;
	while (!ft_strchr(METACHARS, str[x]))
		x--;
	if (i - x <= 0)
		return (1);
	return (0);
}

int syntax_pars_2(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if ((str[i] == '<' && str[i + 1] != '<')
				|| (str[i] == '>' && str[i + 1] != '>'))
		{
			i++;
			if (cheack_back(str, i - 2) || cheack_front(str, &i))
			{
					write(2 ,"Minishell: syntax error near unexpecte token `newline1'\n", 58);
					return (1);
			}
		}
		else if ((str[i] == '>' && str[i + 1] == '>'))
		{
			i += 2;
			if (cheack_back(str, i - 3) || cheack_front(str, &i))
			{
					write(2 ,"Minishell: syntax error near unexpecte token `newline1'\n", 58);
					return (1);
			} 
		}
		else if (str[i] == '<' && str[i + 1] =='<')
		{
			i += 2;
			if (cheack_front(str, &i))
			{
					write(2 ,"Minishell: syntax error near unexpecte token `newline1'\n", 58);
					return (1);
			} 
		}
		else if (str[i] == '|')
		{
			i++;
			if (cheack_back(str, i - 2) || cheack_front(str, &i))
			{
					write(2 ,"Minishell: syntax error near unexpecte token `newline1'\n", 58);
					return (1);
			}
		}
		else 
			i++;
	}
	return (0);
}

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

int	syntax_pars(t_tokens **token)
{
	t_tokens	*node;
	//int			i;

	//i = 0;
	node = *token;
	if (syntax_pars_1(node->rdl[0]))
		return (1);
	if (syntax_pars_2(node->rdl))
	 	return (1);	
	return (0);
}

int	gen_parsing(t_tokens **token, char *str)
{
	t_tokens	*node;

	node = *token;
	node->rdl = ft_strtrim(str, " ");
	if (syntax_pars(token))
		return (1);
	return (0);
}
