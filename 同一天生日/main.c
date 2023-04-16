/*
【问题描述】在一个有200人的大班级中，存在两个人生日相同的概率非常大，现给出每个学生的学号，出生月日，试找出所有生日相同的学生。
【输入形式】第一行为整数n，表示有n个学生，n<=200。此后每行包含一个字符串和两个整数，分别表示学生的学号(字符串长度为11位)和出生月(1<=m<=12)日(1<=d<=31)，学号、月、日之间用一个空格分隔。
【输出形式】对每组生日相同的学生，输出一行，其中前两个数字表示月和日，后面跟着所有在当天出生的学生的学号，数字、学号之间都用一个空格分隔。对所有的输出，要求按日期从前到后的顺序输出。对生日相同的学号，按输入的顺序输出。
【样例输入】6
                   07101020105 3 15
                   07101020115 4 5
                   07101020118 3 15
                   07101020108 4 5
                   07101020111 4 5
                   07101020121 8 10
【样例输出】3 15 07101020105 07101020118
                    4 5 07101020115 07101020108 07101020111

                    8 10 07101020121
【样例说明】输出样例如上。
*/ 

#include <stdio.h>
#include <string.h>

inline int earlier(unsigned int m1, unsigned int d1, unsigned int m2, unsigned int d2)
{
    return m1 < m2 || (m1 == m2 && d1 < d2); 
}

inline int same(unsigned int m1, unsigned int d1, unsigned int m2, unsigned int d2)
{
    return m1 == m2 && d1 == d2;
}

int main(int argc, char **argv)
{
    int days[200];
    int months[200];
    char id[200][12];
    unsigned int n = 0;
    scanf("%d", &n);
    unsigned int i = 0;
    for(;i < n; i++)
    {
        scanf("%s %d %d", id[i], months + i, days +i);
    }

    for(i = 0;i < n; i++)
    {
        unsigned int j = i;
        for(; j > 0; j--)
        {
            if(earlier(months[j], days[j], months[j - 1], days[j - 1]))
            {
                int temp = months[j];
                months[j] = months[j - 1];
                months[j - 1] = temp;

                temp = days[j];
                days[j] = days[j - 1];
                days[j - 1] = temp;

                char tempS[12];
                strcpy(tempS, id[j]);
                strcpy(id[j], id[j - 1]);
                strcpy(id[j - 1], tempS);
            }
        }
    }

    for(i = 0;i < n;)
    {
        printf("%d %d %s", months[i], days[i], id[i]);
        
        unsigned int j = i + 1;
        for(; j < n; j++)
        {
            if(same(months[j], days[j], months[j - 1], days[j - 1]))
            {
                printf(" %s",id[j]);
            }
            else
            {
                break;
            }
        }
        printf("\n");
        i = j;
    }
    return 0;
}