#include "minishell.h"

char	**split_export(char *str)
{
	int		i;
	int		len;
	int		flag;
	char	**ptr;

	i = 0;
	flag = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '=' && flag == 0)
		{
			i++;
			ptr = (char **)malloc (sizeof(char *) * (3));
			ptr[0] = ft_substr(str, 0, i - 1);
			ptr[1] = ft_substr(str, i, len - 1);
			ptr[2] = "\0";
			flag = 1;
		}
		else 
		{

		}
		i++;
	}
	return (ptr);
}
