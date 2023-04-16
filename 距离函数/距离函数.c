#include <stdio.h>
#include <math.h>

#define DEPTH 3

int main(int argc, char **argv)
{
	float xList[DEPTH] = { 0 };
	float yList[DEPTH] = { 0 };
	double d = 0.0f;
	for (int i = 0; i < DEPTH; i++)
	{
		scanf("%f %f", &xList[i], &yList[i]);
	}

	for (unsigned int i = 0; i < DEPTH; i++)
	{
		for (unsigned int j = i + 1; j < DEPTH; j++)
		{
			d += sqrt(pow(xList[j] - xList[i], 2) + pow(yList[j] - yList[i], 2));
		}
	}
	printf("%.2f", d);
	return 0;
}