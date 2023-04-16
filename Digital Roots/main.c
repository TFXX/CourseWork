/*【问题描述】The digital root of a positive integer is found by summing the digits of the integer. If the resulting value is 
                        a single digit then that digit is the digital root, If the resulting value contains two or more digits,those digits 
                        are summed and the process is repeated.This is continued as long as necessary to obtain a single digit.
                             For example, consider the positive integer 24.  Adding the 2 and the 4 yields a value of 6.  Since 6 is a 
                        single digit, 6 is the digital root of 24. Now consider the positive integer 39.  Adding the 3 and the 9 yields 
                        12, since 12 is not a single digit, the process must be repeated. Adding the 1 and the 2 yields 3, a single 
                        digit and also the digital root of 39.
【输入形式】The input file will contain a list of positive integers,one per line.The end of the input will be indicated by an 
                        integer value of zero.
【输出形式】For each integer in the input, output its digital root on a separate line of the output.
【样例输入】24
                        39
                        0
【样例输出】6
                        3
【样例说明】样例如上。*/

#include "stdio.h"

unsigned int cal_digital_root(unsigned int num)
{
    if(num < 10)
    {
        return num;
    }

    unsigned int sum = 0;
    while(0 != num)
    {
        sum += num % 10;
        num /= 10;
    }

    return cal_digital_root(sum);
}

int main(int argc, char **argv)
{
    unsigned int num = 0;
    scanf("%d", &num);
    while(num != 0)
    {
        printf("%d\n", cal_digital_root(num));
        scanf("%d", &num);
    }
	return 0;
}