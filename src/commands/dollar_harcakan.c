#include "minishell.h"

void dollar_harcakan()
{
    char *tiv;
(void)tiv;
    tiv = ft_itoa(exit_code);
    write(1, tiv, ft_strlen(tiv));
    write(1, ":", 1);
    write(1,  "command not found", 18);
}
//127: command not found
