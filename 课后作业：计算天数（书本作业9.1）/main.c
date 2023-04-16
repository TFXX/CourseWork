/*
问题描述

定义一个结构体变量（包括年、月、日）。输入某年某月某日，计算该日在本年中是第几天，注意闰年问题。

输入形式

输入一行，包括三个正整数，表示某年某月某日。

输出形式

输出一行，输出这一天是这一年的第几天。

样例输入

2013 3 5

样例输出

64
*/
#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int y,m,d;
	scanf("%d %d %d", &y, &m, &d);
	unsigned int t[12] = {31, 28, 31, 30, 31 ,30, 31, 31, 30, 31, 30, 31};
	unsigned int i = 1;

	if(((y % 4 == 0) && (y % 100 != 0)) || (y % 400 ==0))
	{
		t[1] += 1;
	}
	for(;i < m; i++)
	{
		d += t[i-1];
	}
	printf("%d", d);
	return 0;
}