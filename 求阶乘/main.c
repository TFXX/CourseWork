#include <stdio.h>

unsigned long long cal_factorial(unsigned long long n)
{
	if(n <= 2)
	{
		return n;
	}
	else
	{
		return cal_factorial(n - 1) * n;
	}
}

int main(int arhc, char **argv)
{
	unsigned long long n = 0;
	scanf("%lld", &n);
	printf("%lld", cal_factorial(n));
	return 0;
}