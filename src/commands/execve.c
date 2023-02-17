
#include "minishell.h"

void create_the_paths(char **splited_path, char *new_str)
{
	int i;
	char *tmp;
	char *ptr;
	//char *lsls;

	i = 0;
	ptr = splited_path[i];
	tmp = splited_path[i];
 	while (splited_path[i])
    {
        splited_path[i] =  ft_strjoin(tmp, new_str);
      	free(tmp);
		tmp = NULL;
		if (splited_path[i + 1])
		{
			tmp = ptr;
			ptr = ft_strjoin(tmp, splited_path[i + 1]);
			//free(tmp);
			tmp = ptr;
		}
        i++;
    }
}

int execve_print(char *str, int z)
{
	(void)str;
	exit_code = z;
	printf("bash: %s: command not found\n", str);
	return (1);
}

void else_wait()
{
	int num;
	(void)num;
	wait(&num);
	if (WIFEXITED(num))
		exit_code = WEXITSTATUS(num);
	
}
int    cheack_access(char **path,char **str, char **mx_env)
{
    int i;
	int flag;
//	int len;
	char *dup;

	dup = NULL;
    i = 0;
	//len = 0;
	flag = 0;
//	len = matrix_len(path);
    while (path[i])
    {
		// printf("1:*path[i] : |%s|\n", path[i]);
		printf("111\n");
        if (access(path[i], F_OK) == 0)
		{
			printf("AAAA\n");
			dup = ft_strdup(path[i]);
			printf("dup =%s\n", dup);
		}
        i++;
		printf("2:*path[i] : |%s|\n", path[i]);
    }
	printf("dup =%s\n", dup);
        if (dup)
			execve(dup, str, mx_env);
		else
			execve_print(str[0], 127);
	return (0);
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
        tmp = ft_strjoin(l_env->key,"=");
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
    char *tmp;
	char *ptr;
    char *new_str;
    char **mx_env;
    int i;

    i = 0;
    path = get_env(env, "PATH");
    splited_path = ft_split(path->value, ':');
    new_str = ft_strjoin("/", str[0]);
    tmp = splited_path[i];
	ptr = splited_path[i];
	create_the_paths(splited_path, new_str);
    // while (splited_path[i])
    // {
    //     splited_path[i] =  ft_strjoin(tmp, new_str);
	// 	if (splited_path[i + 1])
	// 		ptr = ft_strjoin(ptr, splited_path[i + 1]);
    //     free(tmp);
	// 	tmp = ptr;
    //      i++;
    // }
    free(new_str);
    mx_env = t_env_to_matrix(env);
    int pid = 0;
    pid = fork();
    if (pid == 0)
        cheack_access(splited_path, str, mx_env);
	else else_wait();
    matrix_free(mx_env);
    matrix_free(splited_path);
}