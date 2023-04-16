/*
问题描述

有n（不大于20）个学生，每个学生的数据包括学号（字符串长度不超过5）、姓名（字符串长度不超过10）、3门课的成绩（整数），从键盘输入n个学生的数据，要求输出3门课的总平均成绩，以及每个学生的数据（包括学号、姓名、3门课成绩、平均成绩）

输入形式

输入n+1行，第1行输入n，表示有n个学生。从第2行到第n+1行输入每个学生的数据（包括学号、姓名、3门课的成绩）

输出形式

输出n+1行。

第1行输出3门课的总平均成绩，保留小数点后两位。

从第2行到第n+1行输入每个学生的数据，包括学号、姓名、3门课的成绩、平均成绩（保留小数点后两位），数据输出所占格式为"%5s%10s%5d%5d%5d%8.2f";

样例输入

3

001 zhang 70 80 90

002 li 89 90 100

003 zhe 60 70 80

样例输出

81.00

001     zhang   70   80   90   80.00

002        li   89   90 100   93.00

003       zhe   60   70   80   70.00
*/

#include <stdio.h>

struct S
{
	char id[32];
	char n[32];
	unsigned int s[3];
	double avg;
}s[100];



int main(int argc, char **argv)
{
	unsigned int n;
	scanf("%d", &n);

	unsigned int total = 0;
	unsigned int i = 0;
	for(; i < n; i++)
	{
		
		scanf("%s %s %d %d %d", s[i].id, s[i].n, s[i].s, s[i].s+1, s[i].s+2);
		s[i].avg = (double)(s[i].s[0] + s[i].s[1] + s[i].s[2]) / 3;
		total += s[i].s[0] + s[i].s[1] + s[i].s[2];
	}
	printf("%.2f\n", (double)total / (n * 3));
	for(i = 0; i < n; i++)
	{
		printf("%5s%10s%5d%5d%5d%8.2f\n", s[i].id, s[i].n, s[i].s[0], s[i].s[1], s[i].s[2], s[i].avg);
	}
	return 0;
}