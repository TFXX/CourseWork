#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int n, m;
	unsigned int totalScoreTable[100] = { 0 };
	scanf("%d %d", &n, &m);
	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int num = 0;
		scanf("%d ", &num);
		totalScoreTable[i] += num;

		unsigned int minNum = num;
		unsigned int maxNum = minNum;
		for (unsigned int j = 1; j < m; j++)
		{
			scanf((j == m - 1)?("%d"):("%d "), &num);

			if (num < minNum)
			{
				minNum = num;
			}

			else if (num > maxNum)
			{
				maxNum = num;
			}

			totalScoreTable[i] += num;

		}
		totalScoreTable[i] -= minNum + maxNum;
	}

	unsigned int maxScore = totalScoreTable[0];
	for (unsigned int i = 1; i < n; i++)
	{
		if (totalScoreTable[i] > maxScore)
		{
			maxScore = totalScoreTable[i];
		}
	}

	printf("%.2f", (float)maxScore / (m - 2));
	return 0;
}