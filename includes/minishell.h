
#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdio.h>

# define METACHARS " |&()<>;\t\n"

typedef struct s_count
{
    int			count_cmd;
    int	count_herdoc; //<<
	int count_redirect;
    // int		count_append; //>>
    // int    count_infile; //<
    // int    count_outfile;  //>
}               t_count;

typedef struct s_tokens
{
    char			**cmd;
    char			**herdoc; //<<
    // char			**append; //>>
    // char            **infile; //<
    // char            **outfile;  //>
    char            **redirect;  //>
    char            *rdl;
	t_count			count;
    struct  s_tokens    *next;
}               t_tokens;

typedef struct s_env t_env;

 struct s_env
{
	char	*key;
	char	*value;
	t_env	*next;
};

void 	parsing(char *str, t_tokens **token);
char	*ft_substr(char *s, int start, int len);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char  *s1, char  *s2);
void 	initializer(t_tokens **token);
int 	count_init(char *str, t_tokens **token);
int 	ft_strlen(char *str);
void	env_cmd(t_env *env);
void	env_init(char **env, t_env *s_env);
char	**ft_split(char const *s, char c);
int pre_parsing(char *str);
int check_redirect(char *str, t_tokens **token, int i);
int check_herdoc(char *str, t_tokens **token, int i);
int check_cmd(char *str, t_tokens **token, int i);

# endif