
#include "minishell.h"

void create_the_paths(char **splited_path, char *new_str)
{
	int i;
	char *tmp;

	i = 0;
 	while (splited_path[i])
    {
		tmp = splited_path[i];
        splited_path[i] =  ft_strjoin(tmp, new_str);
      	free(tmp);
		tmp = NULL;
        i++;
    }
}

void else_wait()
{
	int num;
	(void)num;
	wait(&num);
	if (WIFEXITED(num))
		exit_code = WEXITSTATUS(num);
	
}

char	*cheack_access(char **path,char **str, char **mx_env)
{
    int i;
	// char *dup1;
	// char *dup;
	(void)mx_env;

	i = 0;
	// dup = NULL;
	// dup1 = NULL;
    while (path[i])
    {
        if (access(path[i], F_OK) == 0)
			return (path[i]);
    	i++;
	}
	return(str[0]);
}

void	ft_execv(char *new_str,char **mx_env, char **str)
{
	(void)new_str;
	
	int i;
	if (str[0][0] == '/' || str[0][0] == '.')
	{
		//printf("ZZZ\n");
		i = execve(str[0], str, mx_env);
		//printf("ZZZ\n");
	}
	else
	{
		printf("FFFF1 = %s\n", new_str);
		i = execve(new_str, str, mx_env);
		printf("FFFF2\n");
	}
	if (i < 0)
		exit(0);
	
	if (i == -1)
	{
		print_error(str[0], "command not found", 127);
	}
	exit(127);
	//return (0);
}


char    **t_env_to_matrix(t_env **env)
{
    t_env   *l_env;
    char    *tmp;
    char    **new_env;
    int     i;

    i = 0;
    l_env = *env;
    new_env = malloc(sizeof(char *) *  env_len(env) + 1);
    while (l_env && l_env->key && l_env->value)
    {
        tmp = ft_strjoin(l_env->key, "=");
        new_env[i] = ft_strjoin(tmp, l_env->value);
        l_env = l_env->next;
        i++;
        free(tmp);
    }
    new_env[i] = 0;
    return (new_env);
}

void execve_cmd(t_env **env, char **str)
{
    t_env *path;
    char **splited_path;
    char *new_str;
    char **mx_env;
    int i;

    i = 0;
    path = get_env(env, "PATH");
    splited_path = ft_split(path->value, ':');
    new_str = ft_strjoin("/", str[0]);
	create_the_paths(splited_path, new_str);
    free(new_str);
    mx_env = t_env_to_matrix(env);
    int pid = 0;
    pid = fork();
    if (pid == 0)
	{
       new_str = cheack_access(splited_path, str, mx_env);
	   printf("smt = %s\n",new_str);
	   ft_execv(new_str, mx_env, str);
	}
	else
		else_wait();
    matrix_free(mx_env);
    matrix_free(splited_path);
}

void execve_cmd2(t_env **env, char **str)
{
    t_env *path;
    char **splited_path;
    char *new_str;
    char **mx_env;
    int i;

    i = 0;
    path = get_env(env, "PATH");
    splited_path = ft_split(path->value, ':');
    new_str = ft_strjoin("/", str[0]);
	create_the_paths(splited_path, new_str);
    free(new_str);
    mx_env = t_env_to_matrix(env);
    // int pid = 0;
    // pid = fork();
    // if (pid == 0)
	// {
        new_str = cheack_access(splited_path, str, mx_env);
		ft_execv(new_str, mx_env, str);
		exit(0); // exiti codery dzel
	// }
	// else
	// 	else_wait();
    matrix_free(mx_env);
    matrix_free(splited_path);
}