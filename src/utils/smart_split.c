#include "minishell.h"

static size_t	word_count(char *str, char delim)
{
	size_t	prev_del;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	prev_del = 1;
	while (str[i])
	{
		if(str[i] && str[i]=='\"')
			i = find_end_of_double_quote(str, i);
		if(str[i] && str[i]=='\'')
			i = find_end_of_single_quote(str, i);
		if (str[i] == delim)
			prev_del = 1;
		else if (prev_del)
			count++;
		if (str[i] != delim)
			prev_del = 0;
		i++;
	}
	return (count);
}

static char	*word_fill(const char *s, size_t start, size_t len)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(len + 1);
	if (word == 0)
		return (0);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static void	*str_free(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (i >= j)
	{
		free(str[j]);
		++j;
	}
	free(str);
	return (0);
}

char	**smart_split(char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	**str;

	i = -1;
	start = 0;
	str = malloc(sizeof (char *) * (word_count(s, c) + 1));
	if (str == 0)
		return (0);
		printf("str = %s\n", s);
	printf("WORD = %zu\n", word_count(s, c));
	while (++i < word_count(s, c) - 1)
	{
		//if(s[start] && s[start]=='\"')
		//	i = find_end_of_double_quote(s, i);
		//if(s[start] && s[start]=='\'')
			i = find_end_of_single_quote(s, i);
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		str[i] = word_fill(s, start, end - start);
		if (!str[i])
			str_free(str, i);
		start = end;
	}
	str[i] = 0;
	return (str);
}