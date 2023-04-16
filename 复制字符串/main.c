/*
问题描述

有一字符串，包含n个字符。写一函数，用指针方法实现将此字符串中从第m个字符开始的全部字符复制成为另一个字符串，其中m小于n。

输入形式

输入两行，第一行是一个字符串，第二行是正整数m。

输出形式

输出一行，给出满足条件复制后的字符串。

样例输入

You are a student.

5

样例输出

are a student.
*/

#include <stdio.h>

int main(int argc, char **argv)
{
	char s[128];
	char *p = s;
	unsigned int d = 0;
	scanf("%[^\n]%*c", s);
	scanf("%d", &d);
	p += d - 1;
	printf("%s", p);
	return 0;
}