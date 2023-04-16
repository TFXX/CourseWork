#include <stdio.h>

void is_prime(int n)
{
	if(n > 2)
	{
		int medium = n / 2;
		if(n % 2 != 0)
		{
			medium ++;
		}
		int i = n - 1;
		for(; i >= medium; i--)
		{
			if(n % i == 0)
			{
				printf("NO");
				return;
			}
		}
		printf("YES");
	}
	else if(n == 2)
	{
		printf("YES");
	}
	else
	{
		printf("error");
	}
}

int main(int argc, char **argv)
{
	int n = 0;
	scanf("%d", &n);
	is_prime(n);
	return 0;
}