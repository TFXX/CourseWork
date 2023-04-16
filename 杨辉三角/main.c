#include <stdio.h>

int main(int argc, char** argv)
{
	unsigned int prev[21];
	unsigned int current[21];
	unsigned int n = 0;
	scanf("%d", &n);

	unsigned int* pPrev = prev;
	unsigned int* pCurrent = current;

	unsigned int i = 0;
	for (; i < n; i++)
	{

		pCurrent[0] = 1;
		unsigned int j = 1;
		for (; j < i + 1; j++)
		{
			if (i > 0)
			{
				pCurrent[j] = pPrev[j - 1] + pPrev[j];
			}
		}

		pCurrent[j] = 0;

		for (j = 0; j < i + 1; j++)
		{
			printf(j == i ? "%d\n" : "%d ", pCurrent[j]);
		}

		unsigned int* temp = pPrev;
		pPrev = pCurrent;
		pCurrent = temp;
	}
	return 0;
}