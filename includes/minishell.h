
#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
 #include <fcntl.h> 
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <string.h>
# include <termios.h>

# define METACHARS " |&()<>;"
# define METAE	"-.!@#$^&*()}{"
extern int	exit_code;

typedef struct s_count	t_count;

struct	s_count
{
    int	count_herdoc; //<<
	int	count_1;
	int count_3;
	int count_4;
};
typedef  struct s_redirects t_redirects;

struct	s_redirects
{
	int		flag;     //< = 1, << =2,  > = 3 >> = 4
	char	*pathname;
	char	*del;
	struct	s_redirects	*next;
};

typedef struct s_tokens	t_tokens;

struct s_tokens
{
    char		*rdl;
    char		**cmd;
	int			*hrd_count;
	int 		token_count;
	//int			istream;
	//int			ostream;
	t_redirects	*head_redct;
	t_tokens	*next;
};

typedef struct s_env	t_env;

 struct	s_env
{
	char	*key;
	char	*value;
    int     flag;
	t_env	*next;
};

//comands
int		exit_cmd(char **c);
void	pwd_cmd(t_env **t_env);
void	env_cmd(t_env *env);
void    unset_cmd(t_env **l_env,char *key);
void	export_cmd(t_env **l_env, char *str);

//
int export_pars(char *str);
int env_len(t_env **l_env);
void shell_level(t_env **env);
void free_t_list(t_tokens **token);
int		ft_strlen(char *str);
void print_error(char *cmd, char *str, int code);
int		pre_parsing(char *str);
t_env	*ft_lstlast(t_env *lst);
void    only_export(t_env **node);
void	export_no_args(t_env **env);
int		cheack_back(char *str, int x);
void dollar_harcakan();
int		count_init( t_tokens **token);
void smart_smart_split(t_tokens **token);
void	initializer(t_tokens **token);
int		cheack_front(char *str, int *x);
void	redirection_output(char *file, int i);
void	redirection_output_append(char *file, int i);
void	 redirection_input(char *file, int i);
void    heredoc(char *key, int i);
void execve_cmd(t_env **env, char **str);
void 	tokenization(t_tokens **token, char **str );
int		find_end_of_double_quote(char *str, int i);
int		find_end_of_single_quote(char *str, int i);
void	cd_cmd(t_env **l_env, char **str);
int		check_longlongd(char *str);
void    redirection_input(char *file, int i);
void	env_init(char **env, t_env **s_env);
int		check_cmd( t_tokens **token, int i);
void	dolar_pars(char **str, t_env **env);
int     find_key(t_env **l_env, char *new_key);
int		check_herdoc( t_tokens **token, int i);
t_env   *get_env(t_env **l_env, char *new_key);
void	ft_lstadd_back(t_env **lst, t_env *new);
int		check_redirect( t_tokens **token, int i);
void	parsing_part_1(char *str, t_tokens **token);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		gen_parsing(t_tokens **token, t_env **env, char **str);
void	one_node_free(t_env **rtv);
void	echo_cmd(char **str);
int		ft_strcrcmp(char *str, char c);
void running(t_tokens **token, t_env **l_env);
char	*join_dolar_str(char *str, char *world, int x, int z);
t_redirects *new_t_redirects(int flag, char *del, char *pathname);
void	t_redirects_add_back(t_redirects **head, t_redirects *new_node);
void    ft_signal_handling(int sig);
void	handleterm(int s);
void    handle_ctrl_d(int sig);
void	interrogatory(char **str);
char	**smart_split1(char *s, char c);
int 	matrix_len(char **str);
void	ft_fill_red(t_tokens **token, int flag, char *str);
int		execve_print(char *str, int z);
void	running_pipe(t_tokens **token, t_env **env);
char	*cheack_access(char **path,char **str, char **mx_env);
char    **t_env_to_matrix(t_env **env);
void 	create_the_paths(char **splited_path, char *new_str);
void running_p(t_tokens **tk, t_env **l_env, int (*fd)[2], int i);
void	child_pr(int (*fd)[2], int i, int count);
void call_heredoc(t_tokens **tk, int len);
t_count *count_all(t_tokens **tk);
void call_redirections(t_tokens **tk, t_count *len);
void ftft(t_tokens **token);
int ft_count_pipe(char *str);
int	check_error(char **tokenized, char *str);
void execve_cmd2(t_env **env, char **str);
int	ft_count_tokens(char **token);

# endif