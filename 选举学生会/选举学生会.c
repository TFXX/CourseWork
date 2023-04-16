#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int n, m;
	unsigned int countTable[999] = { 0 };
	scanf("%d %d", &n, &m);
	for (unsigned int i = 0; i < m; i++)
	{
		unsigned int index = 0;
		scanf((i == m - 1)?"%d":"%d ", &index);
		countTable[index - 1]++;
	}

	for (unsigned int i = 0; i < 999 && n > 0; i++)
	{
		if(countTable[i] != 0)
		{
			unsigned int count = countTable[i];
			for (unsigned int j = 0; j < count; j++)
			{
				printf((j == count - 1 && n == 1)?"%d":"%d ", i + 1);
			}
			n --;
		}
	}
	return 0;
}