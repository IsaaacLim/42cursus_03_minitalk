#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <signal.h>
# include <stdio.h> //remove
# include <unistd.h>
# include <stdlib.h>

void	ft_completed(int sig);
void	ft_failed(int type);

#endif