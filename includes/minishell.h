
#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define METACHARS " |&()<>;"

typedef struct s_count	t_count;

struct	s_count
{
    int	count_cmd;
    int	count_herdoc; //<<
	int	count_redirect;
};

typedef struct s_tokens	t_tokens;

struct s_tokens
{
    char		**cmd;
    char		**herdoc; //<<
    char		**redirect;  //>
    char		*rdl;
	t_count		count;
	t_tokens	*next;
};

typedef struct s_env	t_env;

 struct	s_env
{
	char	*key;
	char	*value;
	t_env	*next;
};

void	env_cmd(t_env *env);
int		ft_strlen(char *str);
int		pre_parsing(char *str);
int		cheack_back(char *str, int x);
int		count_init( t_tokens **token);
void	initializer(t_tokens **token);
int		cheack_front(char *str, int *x);
void	env_init(char **env, t_env *s_env);
int		check_cmd( t_tokens **token, int i);
int		dolar_pars(char *str, t_env **env);
int		check_herdoc( t_tokens **token, int i);
int		check_redirect( t_tokens **token, int i);
void	parsing_part_1(char *str, t_tokens **token);
int		gen_parsing(t_tokens **token, t_env **env, char *str);

# endif