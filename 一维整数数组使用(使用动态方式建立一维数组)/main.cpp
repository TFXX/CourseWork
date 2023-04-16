/*
【问题描述】在函数void f(int n)中动态建立一个大小为n的一维整型数组，并对每个数组元素依次赋值为1，2，3，...，n， 再输出所有元素的和，退出函数前释放此数组。编写主函数，进行测试。
【输入形式】输入数组元素个数n。
【输出形式】数组中所有元素的和。
【样例输入】5
【样例输出】15

【样例说明】元素个数为5的数组，它的各元素分别为1、2、3、4、5，各元素之和为15.

【评分标准】本题15分，共3个测试点，每个测试点5分。
【编程说明】本题必须使用函数void f(int n)，且在函数中动态建立一个大小为n的一维整型数组，不按要求的程序不得分。
*/

#include <iostream>
#include <iterator>

void f(int n)
{
	int *nums = new int[n];
	for(int i = 0; i < n; i++)
	{
		nums[i] = i + 1;
	}
	int total = 0;
	for(int i = 0; i < n; i++)
	{
		total += nums[i];
	}
	std::cout << total;
	delete[] nums;
}

int main(int argc, char **argv)
{
	std::istream_iterator<int> input_int(std::cin);
	f(*input_int);
	return 0;	
}