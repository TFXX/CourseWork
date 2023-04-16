/*
问题描述

输入一行文字，找出其中大写字母、小写字母、空格、数字以及其他字符各有多少。用指针方法实现。

输入形式

输入一行，输入一字符串（字符串的字符不多于80个）。

输出形式

输出一行，出其中大写字母、小写字母、空格、数字以及其他字符各有多少个。各个数值之间以空格分隔。

样例输入

It is a dog. 2 or 3 years old?

样例输出

1 17 8 2 2
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
	unsigned int ua = 0, la = 0, d = 0, space = 0, other = 0;
	char s[81];
	scanf("%[^\n]%*c", s);
	unsigned int i = 0;
	for(;i < strlen(s); i++)
	{
		char c = s[i];
		if(isalpha(c))
		{
			if(islower(c))
				la++;
			else
				ua++;
		}
		else if(isdigit(c))
			d++;
		else if(isspace(c))
			space++;
		else
			other++;
	}
	printf("%d %d %d %d %d", ua, la, space, d, other);
	return 0;
}