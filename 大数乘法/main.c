#include <stdio.h>
#include <string.h>

#define N1 200
#define N2 400

int main(int argc, char** argv)
{
	char bigA[N1];
	char bigB[N1];
	char bigRes[N2];

	unsigned int k = 0;
	for (k = 0; k < N2; k++)
	{
		bigRes[k] = 0;
	}

	fgets(bigA, N1 + 2, stdin);
	unsigned int aLength = strlen(bigA) - 1;

	fgets(bigB, N1 + 2, stdin);
	unsigned int bLength = strlen(bigB) - 1;

	unsigned int i = 0;
	unsigned int j = 0;


	for (i = 0; i < aLength; i++)
	{
		if ('0' == bigA[aLength - 1 - i])
		{
			// ÓÅ»¯
			continue;
		}

		unsigned int exceed = 0;
		unsigned int singalNum = bigA[aLength - 1 - i] - '0';
		for (j = 0; j < bLength; j++)
		{
			unsigned int temp = singalNum * (bigB[bLength - 1 - j] - '0') + exceed + bigRes[i + j];
			exceed = temp / 10;
			bigRes[i + j] = temp % 10;
		}
		bigRes[i + j] += exceed;
	}

	for (i = N2; i > 0; i--)
	{
		if (bigRes[i - 1] != 0)
		{
			break;
		}
	}

	for (; i > 0; i--)
	{
		printf("%d", bigRes[i - 1]);
	}

	return 0;
}