#include "minishell.h"

char	*ft_cat_str1(char *s, int i, int flag)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 2));
	if (str == NULL)
		return (NULL);
	if (flag == 1)
		str[j++] = '-';
	else if (flag == 2)
			str[j++] = '+';
	while (s[i] && i < ft_strlen(s))
		str[j++] = s[i++];
	str[j] = '\0';
	if (j == 0)
		return ("0");
	else
		return (str);
}

char	*ft_cat_str(char *s)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	if (s[i] == '-')
	{
		flag = 1;
		i++;
	}
	if (s[i] == '+')
	{
		i++;
		flag = 2;
	}
	while (s[i] == '0')
	i++;
	return (ft_cat_str1(s, i, flag));
}
