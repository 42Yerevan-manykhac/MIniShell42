#include "minishell.h"
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	
		i++;
	return (i);
}


char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int	i;
	int	k;

	i = 0;
	if (start > ft_strlen(s))
		k = 0;
	else if (ft_strlen(s) - start > len)
		k = len;
	else
		k = ft_strlen(s) - start;
	printf("jjjj =====> %d\n",len);
	str = (char *) malloc(sizeof(char) * (k + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] && len > 0 && start < ft_strlen(s))
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;
	unsigned char	*s;
	int				len;

	s = (unsigned char *) str;
	len = ft_strlen(str);
	i = 0;
	if (c == 0)
		return ((char *)s + len);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
int ft_strcmp(char *str, char *cmd)
{
	int i;
	int j;
	int len;
int flag = 0;
	i = 0;
	j = 0;
	len = ft_strlen(cmd);
	while (cmd && str && cmd[j] && str[i])
	{
		while (str[i] == cmd[j])
		{
			if (j == len - 1)
				return (1);
				
			i++;
			j++;
		}
		if (j == 0)
				flag =1;
			j = 0;
		if (flag)
		{
			i++;
			flag =0;
		}
				
	}
	return (0);
}
char	*ft_strjoin(char *s1, char *s2)
{
		char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}