/*
【问题描述】某班期末考试后要统计本班某门课程的平均成绩、最高成绩和最低成绩，你的任务是编程序实现这一功能。 一个班的人数不超过30人，要求实现求最高成绩，最低成绩和平均成绩的功能用一个count函数完成，并用参数返回最高成绩，最低成绩和平均成绩。提示：count函数的声明为：void count(int a[],int n,int *pmax,int *pmin,float *pave) ;
【输入形式】一组测试数据，第一行为一个整数N，表示本班有N个人（N<=30），接下来的N行中每行一个整数，表示一个人的成绩。
【输出形式】输出一行。该行包含三个数，分别是：最高成绩、最低成绩和平均成绩。成绩之间由空格分隔，其中平均成绩为实数，并精确到小数点后两位。
【样例输入】5
                   90 
                   83
                   76
                   85
                   62
【样例输出】90 62 79.20
【样例说明】某班有5个学生，他们的成绩分别是90、83、76、85、62。该班的最高成绩、最低成绩和平均成绩分别为90、62以及79.20。
【评分标准】本题共2个测试点，每个测试点1分，共2分。
*/
#include <stdio.h>

void count(unsigned int *a, unsigned int n, unsigned int *pMax, unsigned int *pMin, double *pAvg)
{
    unsigned indexMax = 0;
    unsigned indexMin = 0;
    unsigned int total = 0;
    unsigned int i = 0;
    for(; i < n; i++)
    {
        total += a[i];
        if(a[i] > a[indexMax])
        {
            indexMax = i;
        }

        if(a[i] < a[indexMin])
        {
            indexMin = i;
        }
    }
    if(pMax)
    {
        *pMax = a[indexMax];
    }
    if(pMin)
    {
        *pMin = a[indexMin];
    }
    if(pAvg)
    {
        *pAvg = (double)total / n;
    }
}

int main(int argc, char **argv)
{
	unsigned int n = 0;
    scanf("%d", &n);
    unsigned int a[128];
    unsigned int i = 0;
    for(; i < n; i++)
    {
        scanf("%d", a + i);
    }
    unsigned int max, min;
    double avg;
    count(a, n, &max, &min, &avg);
    printf("%d %d %.2f", max, min, avg);
    return 0;
}