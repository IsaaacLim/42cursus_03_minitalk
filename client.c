int ft_putstr(char *str);

int main(int argc, char **argv)
{
	if (argc != 3)
		ft_putstr("./client <PID> \"Message\"\n");
	else
		ft_putstr("ok\n");
}