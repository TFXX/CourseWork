/*问题描述

有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前n项之和。n的值由scanf输入。

（用double保留浮点数据）

输入形式

输入一行，包括n的值。

输出形式

输出一行，给出前n项之和，保留小数点后6位。

样例输入

2

样例输出

3.500000*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char **argv)
{
	int a1 = 1;
	int a2 = 2;
	unsigned int n = 0;
	scanf("%d", &n);
	unsigned int i = 0;
	double sum = 0.0f;
	for(; i < n; i++)
	{
		sum += (double)a2 / a1;

		a2 += a1;
		a1 = a2 - a1;
	}
	printf("%.6f", sum);
	return 0;
}