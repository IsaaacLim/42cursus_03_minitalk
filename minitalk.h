#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <signal.h>
# include <stdio.h> //remove
# include <unistd.h>
# include <stdlib.h>

typedef struct s_serverVar
{
	char	c;
	int		shift;
}	t_serverVar;

t_serverVar g_var;

void	ft_completed(int sig);
void	ft_failed(int type);

#endif