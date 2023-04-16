/*【问题描述】在国外，每月的13号和每周的星期5都是不吉利的。特别是当13号那天恰好是星期5时，更不吉利。已知
                        某年的一月一日是星期W，并且这一年一定不是闰年，求出这一年所有13号那天是星期5的月份，按从小
                        到大的顺序输出月份数字。(W=1..7)
【输入形式】输入有一行，即一月一日星期几(W)。(1<=w<=7)
【输出形式】输出有一到多行，每行一个月份，表示该月的13日是星期五。
【样例输入】7
【样例输出】1
                        10
【样例说明】1月1日是星期7的年，1月、10月都是不吉利日期。*/

#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned int dayTable[] = {12, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    unsigned int xingQi = 0;
    scanf("%d", &xingQi);

    unsigned int i = 0;
    for(; i < 12; i++)
    {
        xingQi = (xingQi + dayTable[i]) % 7;
        if(5 == xingQi)
        {
            printf("%d\n", i + 1);
        }
    }
	return 0;
}