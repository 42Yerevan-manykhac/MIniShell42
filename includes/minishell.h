
#ifndef MINISHELL_H
# define MINISHELL_H

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

# define METACHARS " |&()<>;"

typedef struct s_count
{
    int			count_cmd;
    int	count_herdoc; //<<
	int count_redirect;
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

void	env_cmd(t_env *env);
int		ft_strlen(char *str);
int		pre_parsing(char *str);
int		count_init( t_tokens **token);
void	initializer(t_tokens **token);
void	env_init(char **env, t_env *s_env);
int		check_cmd( t_tokens **token, int i);
int		check_herdoc( t_tokens **token, int i);
int		check_redirect( t_tokens **token, int i);
int		gen_parsing(t_tokens **token, char *str);
void	parsing_part_1(char *str, t_tokens **token);

# endif