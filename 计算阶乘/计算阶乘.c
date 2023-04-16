#include <stdio.h>

unsigned int factorial(unsigned int num)
{
	if(num == 1)
	{
		return 1;
	}

	return num * factorial(num - 1);
}

int main(int argc, char **argv)
{
	unsigned int num = 0;
	scanf("%d", &num);
	printf("%d", factorial(num));
}