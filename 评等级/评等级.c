#include <stdio.h>

#define NUM 999

typedef struct{
	char number[7];
	unsigned int grades;
	unsigned int extendGrades;
} student_t;

int is_excellent(student_t *pStu)
{
	if (pStu -> grades + pStu -> extendGrades > 140 && pStu -> grades * 7 + pStu -> extendGrades * 3 >= 800)
	{
		return 1;
	}

	return 0;
}

int main(int argc, char **argv)
{
	student_t stuTable[NUM];

	unsigned int n = 0;
	scanf("%d", &n);

	unsigned int i = 0;
	for (; i < n; i++)
	{
		scanf("%s %d %d", stuTable[i].number, &stuTable[i].grades, &stuTable[i].extendGrades);
	}

	for (; i > 0; i--)
	{
		if (is_excellent(stuTable + n - i))
		{
			printf("Excellent\n");
		}
		else
		{
			printf("Not excellent\n");
		}
	}
	return 0;
}