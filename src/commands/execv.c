
#include "minishell.h"

char **t_env_to_matrix(t_env **env)
{
    t_env *l_env;
    char *tmp;
    char **new_env;
    int i;

    i = 0;
    l_env = *env;
    new_env = malloc(sizeof(char *));
    while (l_env && l_env->key)
    {
        tmp = ft_strjoin(l_env->key,"=");
        new_env[i] = ft_strjoin(tmp, l_env->value);
        l_env = l_env->next;
        printf("new = %s\n", new_env[i]);
        i++;
        free(tmp);
    }
    new_env[i] = 0;
     i = 0;
    //  while (new_env[i])
    //     printf("str = %s\n", new_env[i++]);
    return (new_env);
}

void execv_cmd(t_env **env, char **str)
{
    t_env *path;
    char **splited_path;
    char *tmp;
    char *new_str;
    char **mx_env;
    int i;
(void)mx_env;
    i = 0;
    path = get_env(env, "PATH");
    splited_path = ft_split(path->value, ':');
    new_str = ft_strjoin("/", str[0]);
    while (splited_path[i])
    {
        tmp = splited_path[i];
        splited_path[i] =  ft_strjoin(tmp, new_str);
        free(tmp);
        printf("path = %s\n", splited_path[i]);
         i++;
    }
    free(new_str);
    mx_env = t_env_to_matrix(env);
    i = 0;
     while (mx_env[i])
        printf("str = %s\n", mx_env[i++]);
    printf("path = %s\n", path->value);
    i = 0;
    matrix_free(mx_env);
    matrix_free(splited_path);
}