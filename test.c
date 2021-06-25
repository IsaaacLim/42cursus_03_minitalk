#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void ft_createStrWithEOFChar(void)
{
	char c = 65;
	char n = '\n';
	char s[2];

	s[0] = 4;
	s[1] = n;
	ft_putstr(s);
}

typedef struct s_serverVar
{
	char	c;
	int		shift;
}	t_serverVar;

t_serverVar g_var = {0, 7};

static void	ft_editGlobalVar()
{
	if (g_var.shift == 6 || g_var.shift == 5 || g_var.shift == 0)
		g_var.c += (1 << g_var.shift);
	else
		g_var.c += (0 << g_var.shift);
	g_var.shift--;
}
void	ft_structGlobalVar()
{
	g_var.c = 65;
	printf("%c %d\n", g_var.c, g_var.shift);
	g_var.c = 0;
	while (g_var.shift != -1)
		ft_editGlobalVar();
	write(1, &g_var.c, 1);
	printf(" %d\n", g_var.shift);
}

int main()
{
	//ft_createStrWithEOFChar();
	ft_structGlobalVar();
}