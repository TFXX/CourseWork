/*问题描述

求方程ax2+bx+c=0的根。用3个函数分别求当b*b﹣4ac大于0、等于0和小于0时的根并输出结果。从主函数输入a、b、c的值。（注意此题没有说明是一元二次方程，所以要考虑a为零的情况）。

输入形式

输入一行，只包括3个浮点数（请在程序中设置为double数据类型），即a、b、c的值。

输出形式

输出一行，给出方程的根，小数点保留两位。若为一个根，则输出一个根，若有两个实根，则输出两个实根（实根大的先输出），两个实根间以空格分隔。若有两个虚根，则输出两个虚根（虚根大的先输出），两个虚根间以空格分隔。

样例输入

1 2 3

样例输出

-1.00+1.41i  -1.00-1.41i*/

#include <stdio.h>
#include <math.h>

void cal(int a, int b, int c)
{
	int delta = b * b - 4 * a * c;
	double n1 = (double ) - b / (2 * a);
	if(a == 0)
	{
		printf("%.2f", (double) -c / b);
	}
		else
		{
		if(delta > 0)
		{
			double n2 = sqrt((double)delta) / (2 * a);
			printf("%.2f %.2f", n1 + n2, n1 - n2);
		}
		else if(delta < 0)
		{
			double n2 = sqrt((double) - delta) / (2 * a);
			printf("%.2f+%.2fi %.2f-%.2fi", n1, n2, n1, n2);
		}
		else
		{
			printf("%.2f", n1);
		}
	}
}

int main(int argc, char **argv)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	cal(a, b ,c);
	return 0;
}