/*
【问题描述】按字符串比较过程对给定的两个字符串进行比较，若相等则结果为0，若不等则结果为对应不等字符的差。按要求实现对给定字符串的比较。要求程序中用函数实现两个字符串的比较。int stringcmp(char *str1 ,char *str2 )
【输入形式】第一行为一个整数N，表示测试数据的组数，接下来的N行中每行包含两个字符串，字符串之间由空格分隔。
【输出形式】输出共N行，每行为对应输入一行的两个字符串的比较结果。
【样例输入】3
                    Happy Help
                    Help Help
                    Help Happy
【样例输出】- 4
                    0
                    4
【样例说明】测试3组字符串。第1组为"Happy"和"Help",第2组为"Help"和"Help"，第3组为"Help"和"Happy";，比较结果分别为-4、0和4。
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int mystrcmp(const char *s1, const char *s2)
{
	unsigned int i = 0;
	for(; i < sizeof(s1); i++)
	{
		if(s1[i] != s2[i])
		{
			return s1[i] - s2[i];
		}
		else
		{
			if(s1[i] == '\0' && s2[i] == '\0')
			{
				return 0;
			}
		}
	}

	return 0;
}

int main(int argc, char **argv)
{
	unsigned int n = 0;
	scanf("%d", &n);
	unsigned int i = 0;
	for(; i < n; i++)
	{
		char s1[128];
		char s2[128];
		scanf("%s%s", s1, s2);
		printf("%d\n", mystrcmp(s1, s2));
	}
	return 0;
}