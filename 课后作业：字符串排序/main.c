/*
问题描述

在主函数中输入n个的字符串。用另一函数用指针方法对它们按照ASCII码从小到大的顺序排序。然后在主函数输出这n个已排好序的字符串。（n不大于10，每个字符串的长度不大于80）

输入形式

输入n+1行，第一行是正整数n，第二行到第n+1行是n个字符串。

输出形式

输出n行，给出排序好的n个字符串。

样例输入

5
Bbbb b
Aaaa a
Ccccc c
Eeeee e
Ddddd

样例输出

Aaaa a

Bbbb b

Ccccc c

Ddddd

Eeeee e

*/

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char s[10][81];
	char *pList[10];
	unsigned int n = 0;
	scanf("%d", &n);
	getchar();
	unsigned int i = 0;
	for(;i < n; i++)
	{
		//gets(s[i]);
		scanf("%[^\n]%*c", s[i]);
		pList[i] = s[i];
	}

	for(i = 0; i < n; i++)
	{
		unsigned min = i;
		unsigned int j = i;
		for(; j < n ;j++)
		{
			if(strcmp(pList[min], pList[j]) > 0)
			{
				min = j;
			}
		}

		char *temp = pList[i];
		pList[i] = pList[min];
		pList[min] = temp;
	}

	for(i = 0; i < n; i++)
	{
		printf(i == n - 1?"%s":"%s\n", pList[i]);
	}
	return 0;
}