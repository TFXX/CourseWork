#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char **argv)
{
	double a1 = 1;
	double a2 = 2;
	unsigned int n = 0;
	scanf("%d", &n);
	unsigned int i = 0;
	double sum = 0.0f;
	double t;
	for(; i < n; i++)
	{
		sum += a2 / a1;
		//printf("%d\n", a2);
		t = a2;
		a2 += a1;
		a1 = t;
	}
	printf("%.2f", sum);
	return 0;
}