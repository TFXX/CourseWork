/*
【问题描述】利用重载函数实现对若干个数据输出最小值。此题要求使用同名函数分别实现：① 对2个实数；② 对3个字符串；③ 对10个整数求最小值。
【输入形式】输入分3行。第1行为2个实数；第2行为3个字符串；第3行为10个整数，各数之间用空格间隔。

【输出形式】占一行，共3个数，分别是2个实数、3个串、10个整数的最小值，各数之间以空格间隔。

【样例输入】20.3 18.02

                        Tuesday Today Tomorrow

                        3 5 7 1 2 4 8 9 10 6

【样例输出】18.02 Today 1

【评分标准】本题共15分，3个测试点，每个测试点5分。
【编程说明】本题必须使用函数重载，非函数重载编程不得分。
*/#include <iostream>
#include <iterator>
#include <vector>

#define D_NUM 2
#define S_NUM 3
#define I_NUM 10

size_t find_min(const std::vector<double> &vec)
{
	size_t min_index = 0;
	for(size_t i = 1; i < vec.size(); i++)
	{
		if(vec[i] < vec[min_index])
		{
			min_index = i;
		}
	}

	return min_index; 
}

size_t find_min(const std::vector<std::string> &vec)
{
	size_t min_index = 0;
	for(size_t i = 1; i < vec.size(); i++)
	{
		if(vec[i] < vec[min_index])
		{
			min_index = i;
		}
	}

	return min_index; 
}

size_t find_min(const std::vector<int> &vec)
{
	size_t min_index = 0;
	for(size_t i = 1; i < vec.size(); i++)
	{
		if(vec[i] < vec[min_index])
		{
			min_index = i;
		}
	}

	return min_index; 
}

int main(int agrc, char **argv)
{
	std::vector<double> vecd(0);

	std::istream_iterator<double> input_double(std::cin);
	for(size_t n = 0; n < D_NUM; n++)
	{
		vecd.emplace_back(*input_double);
		if(D_NUM - 1!= n)
		{
			input_double++;
		}
	}

	std::vector<std::string> vecs(0);
	std::istream_iterator<std::string> input_string(std::cin);
	for(size_t n = 0; n < S_NUM; n++)
	{
		vecs.emplace_back(*input_string);
		if(S_NUM -1 != n)
		{
			input_string++;
		}
	}

	std::vector<int> veci(0);
	std::istream_iterator<int> input_int(std::cin);
	for(size_t n = 0; n < I_NUM; n++)
	{
		veci.emplace_back(*input_int);
		if(I_NUM -1 != n)
		{
			input_int++;
		}
	}

	

	std::cout << vecd[find_min(vecd)] << " " << vecs[find_min(vecs)] << " " << veci[find_min(veci)];
}