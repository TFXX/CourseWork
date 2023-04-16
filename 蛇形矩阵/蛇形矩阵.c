#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int numTable[9][9] = { 0 };
	unsigned int size = 0;
	scanf("%d", &size);

	unsigned int count = 1;

	int i = size;
	
	for(int i = 0; i < (size + 1) / 2; i ++)
	{
		int j = i;
		int k = j;

		if (j == size - i - 1)
		{
			numTable[k][j] = count++;
		}

		for(; j < size - i - 1; j++)
		{
			numTable[k][j] = count++;
		}

		
		for(; k < size - i - 1; k++)
		{
			numTable[k][j] = count ++;
		}

		for(; j > i; j--)
		{
			numTable[k][j] = count ++;
		}

		for(; k > i; k--)
		{
			numTable[k][j] = count ++;
		}
	}

	for(unsigned int i = 0; i < size; i++)
	{
		for(unsigned int j = 0; j < size; j++)
		{
			printf("%3d", numTable[i][j]);
		}

		printf("\n");
	}

	return 0;
}
