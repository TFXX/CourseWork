#include <stdio.h>

#define NUM 999

int main(int argc, char **argv)
{
	char nameTable[NUM][8 + 1];
	unsigned int cScoreTable[NUM];
	unsigned int mScoreTable[NUM];
	unsigned int eScoreTable[NUM];

	unsigned int n = 0;
	scanf("%d", &n);

	scanf("%s %d %d %d", nameTable, cScoreTable, mScoreTable, eScoreTable);
	unsigned int maxScore = cScoreTable[0] + mScoreTable[0] + eScoreTable[0];
	unsigned int maxScoreIndex = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		scanf("%s %d %d %d", nameTable + i, cScoreTable + i, mScoreTable + i, eScoreTable + i);
		unsigned int score = cScoreTable[i] + mScoreTable[i] + eScoreTable[i];
		if (score > maxScore)
		{
			maxScoreIndex = i;
			maxScore = score;
		}
	}

	printf("%s %d %d %d", nameTable[maxScoreIndex], cScoreTable[maxScoreIndex], mScoreTable[maxScoreIndex], eScoreTable[maxScoreIndex]);
	return 0;
}