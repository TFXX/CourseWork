/*问题描述

写一转换函数，实现十六进制数向十进制数的转换。主函数中输入一个十六进制数，输出相应的十进制数。转换功能是转换函数完成。

输入形式

输入一行，只包括一个十六进制数，输入的字母可大写也可小写，如A0与a0表示同样的数。

输出形式

输出一行，输出相应的十进制数。

样例输入

A0

样例输出

160*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htod(char c)
{
	if(isdigit(c))
	{
		return c - '0';
	}
	else if(isupper(c))
	{
		return c - 'A' + 10;
	}
	else
	{
		return c - 'a' + 10;
	}
}

int hstod(char *s)
{
	unsigned int i = strlen(s);
	int sum = 0;
	unsigned int base = 1;
	for(; i > 0; i--)
	{
		sum += htod(s[i-1]) * base;
		base *= 16;
	}
	return sum;
}

int main(int argc, char **argv)
{
	char s[32];
	scanf("%s", s);
	printf("%d", hstod(s));
	return 0;
}