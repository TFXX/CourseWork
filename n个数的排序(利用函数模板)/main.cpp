/*
【问题描述】利用函数模板，实现对n个数据的由小到大排序。此题要求分别使用5个整型、3个字符串、8个实型三种类型的数据进行测试。
【输入形式】输入占三行。第一行是5个整型；第2行是3个字符串；第3行是8个实型，彼此用空格间隔。
【输出形式】占3行，分别是由小到大排序的n个数，彼此用空格间隔。【提示：本题不用管实数的小数点位数，正常使用cout输出变量即可。本题重点在于：学会使用函数模板。】
【样例输入】5 4 3 2 1 

                        Tuesday Today Tomorrow

                        1.2 5.6 3.5 6.7 7.8 1.1 9.3 2.4

【样例输出】1 2 3 4 5

                         Today Tomorrow Tuesday

                        1.1 1.2 2.4 3.5 5.6 6.7 7.8 9.3
【评分标准】本题15分，共3个测试点，每个测试点5分。
【编程说明】本题必须使用函数模板，非函数模板编程不得分。
*/

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

#define I_NUM 5
#define D_NUM 8

#define S_NUM 3

template<typename Iterator>
Iterator sort(Iterator first, Iterator last)
{
	for(Iterator i = first; i != last; i++)
	{
		Iterator min = i;
		for(Iterator j = i; j != last; j++)
		{
			if(*j < *min)
			{
				min = j;
			}
		}

		std::iter_swap(i, min);
	}

	return first;
}

int main(int argc, char **argv)
{
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

	std::copy(sort(veci.begin(), veci.end()), veci.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::copy(sort(vecs.begin(), vecs.end()), vecs.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
	std::copy(sort(vecd.begin(), vecd.end()), vecd.end(), std::ostream_iterator<double>(std::cout, " "));
	
	
}