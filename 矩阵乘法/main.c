#include <stdio.h>

int main(int argc, char** argv)
{
	unsigned int m, n, p;
	scanf("%d %d %d", &m, &n, &p);

	int martixA[10][10];
	int martixB[10][10];

	unsigned int i = 0;
	unsigned int j = 0;

	for (i = 0; i < m; i++)
	{

		for (j = 0; j < n; j++)
		{
			scanf("%d", martixA[i] + j);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p; j++)
		{
			scanf("%d", martixB[i] + j);
		}
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < p; j++)
		{
			unsigned int k = 0;
			int sum = 0;
			for (; k < n; k++)
			{
				sum += martixA[i][k] * martixB[k][j];
			}
			printf((j == p - 1) ? "%d\n" : "%d ", sum);
		}
	}

	return 0;
}