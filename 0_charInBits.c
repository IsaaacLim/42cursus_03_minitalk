# include <stdio.h>
# include <unistd.h>
# include <signal.h>

void	create_char_with_bits(void)
{
	char a;

	a += 0 << 7; //8th for neg number
	a += 1 << 6;
	a += 1 << 5;
	a += 0 << 4;
	a += 0 << 3;
	a += 0 << 2;
	a += 0 << 1;
	a += 1 << 0;
	write(1, &a, 1);
	printf("\n");
}

//https://stackoverflow.com/questions/18327439/printing-binary-representation-of-a-char-in-c
//can try to send signals with this
void	print_char_in_bits(char a)
{
  int i;
  for (i = 0; i < 8; i++) {
      printf("%d", !!((a << i) & 0x80)); //print from left to right
  }
  printf("\n");
}

static char c;
static char size = 7;

void	print_bits_in_char(int bit) //receiving 1/0 only
{
	c += ((bit & 1) << size); //stringing left to right (== works too)
	size--;
	if (size == -1) //7 to 0 offset must be completed
	{
		write(1, &c, 1);
		if (!c)
			write(1,"\n", 1);
		c = 0; //NULL?
		size = 7;
	}
}

int main()
{
	create_char_with_bits();
	print_char_in_bits('a');

	print_bits_in_char(0); //8th bit
	print_bits_in_char(1); //7th bit
	print_bits_in_char(1); //6th bit
	print_bits_in_char(0); //5th bit
	print_bits_in_char(0); //4th bit
	print_bits_in_char(0); //3rd bit
	print_bits_in_char(0); //2nd bit
	print_bits_in_char(1); //1st bit
	printf("\n");
	printf("%d\n", SIGUSR1);
}