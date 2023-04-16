/*【问题描述】判断一个由a-z 这26个字符组成的字符串中哪个字符出现的次数最多。
【输入形式】第1行是测试数据的组数n,每组测试数据占1行，是一个由a-z这26个字符组成的字符串，每行数据不超过
                        1000个字符且非空。
【输出形式】输出n行，每行输出对应一个输入。一行输出包括出现次数最多的字符和该字符出现的次数，中间是一个
                        空格。如果有多个字符出现的次数相同且最多，那么输出ASCII码最小的那一个字符。
【样例输入】2
           abbccc
           adfadffasdf
【样例输出】c 3
            f 4
【样例说明】输出样例如上。*/

#include <stdio.h>

void cal_char(char *s)
{
    unsigned int hash[26];

    unsigned int i = 0;
    for(;i < 26; i++)
    {
        hash[i] = 0;
    }

   
    for(i = 0; s[i] != '\0'; i++)
    {
        hash[s[i] - 'a']++;
    }

    unsigned int max = 0;
    for(i = 0; i < 26; i++)
    {
        if(hash[i] > hash[max])
        {
            max = i;
        }
    }

    printf("%c %d\n", max + 'a', hash[max]);
}

int main(int argc, char **argv)
{

    unsigned int d = 0;
    scanf("%d", &d);
    char s[1001];
    for(; d > 0; d--)
    {
        scanf("%s", s);
        cal_char(s);
    }
    return 0;
}