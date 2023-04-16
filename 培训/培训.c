#include <stdio.h>

#define NUM 5

typedef struct{
	char name[128];
	unsigned int age;
	unsigned int grades;
} student_t;

int main(int argc, char **argv)
{
	student_t stuTable[NUM];

	unsigned int n = 0;
	scanf("%d", &n);

	unsigned int i = 0;
	for (; i < n; i++)
	{
		scanf("%s %d %d", stuTable[i].name, &stuTable[i].age, &stuTable[i].grades);
	}

	for (; i > 0; i--)
	{
		stuTable[n - i].age += 1;
		stuTable[n - i].grades = stuTable[n - i].grades / 5 * 6;
		stuTable[n - i].grades -= (stuTable[n - i].grades / 600) * stuTable[n - i].grades % 600;
		printf("%s %d %d\n", stuTable[n - i].name, stuTable[n - i].age, stuTable[n - i].grades);
	}
	return 0;
}