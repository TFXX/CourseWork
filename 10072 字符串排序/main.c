/*
【问题描述】按字典顺序输出某班所有人的名单。
【输入形式】一组测试数据，第一行为一个整数N，表示本班有N个人(N<=30)，接下来的N行中每行一个人名 (人名均由小写字母组成，并且名字长度小于20)。
【输出形式】按字典顺序排列的人员名单。每个人名占一行。
【样例输入】5
                    zhangsan
                    liyang
                    wangxiao
                    liqing
                    wuhui
【样例输出】liqing
                    liyang
                    wangxiao
                    wuhui
                    zhangsan
【样例说明】某班有5个人,名字为zhangsan、liyang、wangxiao、liqing、wuhui,  
                   按字典的排列顺序为：liqing、liyang、wangxiao、wuhui、zhangsan。
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define N 30
#define SIZE 20

void swap(const char **s1, const char **s2)
{
	const char *temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void sort(const char **a, unsigned int n)
{
	unsigned int i = 0;
	for(; i < n; i++)
	{
		unsigned minIndex = i;
		unsigned int j = i + 1;
		for(; j < n; j++)
		{
			if(strcmp(a[minIndex], a[j]) > 0)
			{
				swap(a + minIndex, a + j);
			}
		}
	}
}

int main(int argc, char **argv)
{
	char s[N][SIZE];
	const char *index[N];
	unsigned int n = 0;
	scanf("%d", &n);
	unsigned int i = 0;
	for(; i < n; i++)
	{
		scanf("%s", s[i]);
		index[i] = s[i];
	}

	sort(index, n);

	for(i = 0; i < n; i++)
	{
		printf("%s\n", index[i]);
	}
	return 0;
}