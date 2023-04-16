/*问题描述

编写一函数，由实参传来一个字符串（长度不大于30），统计此字符串中字母、数字、空格和其他字符的个数，在主函数中输入字符串以及输出上述的结果。

输入形式

输入一行，输入一字符串。

输出形式

输出一行，字符串中字母、数字、空格和其他字符的个数。各个数值之间以空格分隔。

样例输入

My class is computer_4.

样例输出

      17 1 3 2

*/
#include <stdio.h>
#include <ctype.h>

void count(char *s)
{
	unsigned int n = 0, a = 0, space = 0, other = 0;
	unsigned int i = 0;
	for(; s[i] != '\0'; i++)
	{
		if(isalpha(s[i]))
		{
			a++;
		}
		else if(isdigit(s[i]))
		{
			n++;
		}
		else if(isspace(s[i]))
		{
			space++;
		}
		else
		{
			other++;
		}
	}
	printf("%d %d %d %d", a, n, space, other);
}

int main(int argc, char **argv)
{
	char s[31];
	scanf("%[^\n]%*c", s);
	count(s);

	return 0;
}