/*
问题描述

完全数是这样一个整数，它加上100后是一个完全平方数，它加上268也是一个完全平方数。编程程序求出m，n之间所有完全数（包括m和n），其中n>m。

输入形式

输入一行，包括整数m和n。

输出形式

输出一行，输出m与n间的所有完全数，各数之间以空格分隔。若没有，则输出no。

样例输入

1 10000

样例输出

        21 261 1581
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(int agrc, char **argv)
{
	int a, b;
	scanf("%d%d", &a, &b);
	int flag = 0;
	for(; a <= b; a++)
	{
		int x = (int)sqrt(a + 100);
		int y = (int)sqrt(a + 268);
		if(x * x == a + 100 && y * y == a + 268)
		{
			flag = 1;
			printf("%d ", a);
		}
	}

	if(!flag)
	{
		printf("no");
	}
	return 0;
}