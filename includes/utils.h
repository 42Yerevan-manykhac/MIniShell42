
#ifndef UTILS_H
# define UTILS_H


# define BLK "\e[0;30m"
# define RED "\033[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define OOO "\033[0m"

char	*ft_itoa(int n);
long long	ft_atoi(const char *str);
void	print_logo();
int     ft_int_strchr(char *str, char c);
char	*ft_strchr(char *str, int c);
char	*ft_strchr(char *str, int c);
char	**split_export(char *str);
char	*ft_strdup( char *s1);
void	matrix_free(char **env_split);
int     ft_strcmp1(char *s1, char *s2);
int		ft_strcmp(char *str, char *cmd);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strjoin(char *s1, char  *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char *s, int start, int len);
char	**smart_split(char *s, char c);
//int     ft_isdigit(int argument);
char	*ft_cat_str(char *s);
int     ft_isdigit(char *str);
void	ft_putstr_fd(char *s, int fd);
char *ignore_quote(char *str);
void *ft_calloc(int c, int s);

# endif