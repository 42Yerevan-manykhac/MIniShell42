#include "minishell.h"

static size_t	word_count(char const *str, char delim)
{
	size_t	prev_del;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	prev_del = 1;
	while (str[i])
	{
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

char	**ft_split(char const *s, char c)
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
	while (++i < word_count(s, c))
	{
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
// static int	unleah(char **str, int size)
// {
// 	while (size--)
// 		free(str[size]);
// 	return (-1);
// }

// static int	count_words(const char *s, char c)
// {
// 	int	i;
// 	int	words;

// 	words = 0;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
// 			&& (s[i] == c || s[i] == '\0') == 0)
// 			words++;
// 		i++;
// 	}
// 	return (words);
// }

// static void	write_word(char *dest, const char *from, char charset)
// {
// 	int	i;

// 	i = 0;
// 	while ((from[i] == charset || from[i] == '\0') == 0)
// 	{
// 		dest[i] = from[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// }

// static int	write_split(char **split, const char *str, char charset)
// {
// 	int		i;
// 	int		j;
// 	int		word;

// 	word = 0;
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if ((str[i] == charset || str[i] == '\0') == 1)
// 			i++;
// 		else
// 		{
// 			j = 0;
// 			while ((str[i + j] == charset || str[i + j] == '\0') == 0)
// 				j++;
// 			split[word] = (char *)malloc (sizeof(char) * (j + 1));
// 			if (split[word] == NULL)
// 				return (unleah(split, word - 1));
// 			write_word(split[word], str + i, charset);
// 			i += j;
// 			word++;
// 		}
// 	}
// 	return (0);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**ptr;
// 	int		words;

// 	words = count_words(s, c);
// 	ptr = (char **)malloc (sizeof(char *) * (words + 1));
// 	if (ptr == NULL)
// 		return (NULL);
// 	ptr[words] = 0;
// 	if (write_split(ptr, s, c) == -1)
// 		return (NULL);
// 	return (ptr);
// }
