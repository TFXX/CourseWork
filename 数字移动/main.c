/*
问题描述

有n个整数，使前面各数顺序向后移m个位置，最后m个数变成前面m个数，见图。

写一函数：实现以上功能，在主函数中输入n个数和输出调整后的n个数。用指针方法实现。

输入形式

输入两行，第一行输入n和m，第二行输入n个整数。

输出形式

输出一行，输出调整后的n个数。

样例输入

6 2

1 2 3 4 5 6

样例输出

5 6 1 2 3 4
*/
#include <stdio.h>

int main(int argc, char **argv)
{
	int nums[128];
	unsigned int n, m;
	scanf("%d %d", &n, &m);
	int *p = nums + m;
	unsigned int i = 0;
	for(;i < n - m; i++)
	{
		scanf("%d", p + i);
	}

	for(i = 0; i < m; i++)
	{
		scanf("%d", nums + i);
	}

	for(i = 0; i < n; i++)
	{
		printf(i == n - 1?"%d":"%d ", nums[i]);
	}

	return 0;
}