
#include "minishell.h"


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

    i = 0;
	flag = 0;
    while (*path[i])
    {
		printf("fds\n");
        if (!access(path[i], F_OK))
		{
			printf("1fds\n");
            if (execve(path[i], str, mx_env) == -1)
			{
				printf("fds");
			flag = 1;

			}
		}
		else flag = 1;
        i++;
    }
	printf("Vahee %d\n",flag );
	if (flag)
	{
		execve_print(str[0], 127);
		return (1);
	}
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
    char *new_str;
    char **mx_env;
    int i;

    i = 0;
    path = get_env(env, "PATH");
    splited_path = ft_split(path->value, ':');
    new_str = ft_strjoin("/", str[0]);
    while (splited_path[i])
    {
        tmp = splited_path[i];
        splited_path[i] =  ft_strjoin(tmp, new_str);
        free(tmp);
         i++;
    }
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