/*【问题描述】编一程序，对于给定的一个百分制成绩，输出相应的五分值成绩。设90分以上为'A'，80-89分为'B，70－79分为'C'，60-69分为'D，,60分以下为'E'(用switch语句实现)。若输入的百分制成绩不在0-100之内，则输出error。

【输入形式】输入一行，包括一个百分制成绩，范围在0-100。

【输出形式】输出一行，给出这个百分制成绩相应的五分值成绩。

【样例输入】100

【样例输出】A*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char **argv)
{
	int score = 0;
	scanf("%d", &score);
	if(score > 100 || score < 0)
	{
		printf("error");
	}
	else
	{
		switch(score / 10)
		{
		case 10:
		case 9:
			printf("A");
			break;
		case 8:
			printf("B");
			break;
		case 7:
		case 6:
			printf("D");
			break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			printf("E");
			break;
		default:
			printf("error");
			break;
		}
	}
	return 0;
}