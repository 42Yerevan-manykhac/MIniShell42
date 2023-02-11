
#include "minishell.h"

void    cheack_access(char **path,char **str, char **mx_env)
{
    int i;

    i = 0;
    while (*path[i])
    {
        if (!access(path[i], F_OK))
            execve(path[i], str, mx_env);
        i++;
    }
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
    usleep(2500);
    matrix_free(mx_env);
    matrix_free(splited_path);
}