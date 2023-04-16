/*
【问题描述】设计一个对三个整数进行操作的类，类中包括：三个整数数据成员；五个成员函数：输入三个数、最大值、平均值、由小到大排序、输出按照由小到大排列顺序的三个数。

            在main()中，以24、36、12三个整数作为测试数据，测试一下类中所有成员函数。

【输入形式】通过键盘输入三个整数，分别是：24、36、12，各数以空格做间隔。注意：通过成员函数输入这三个数。

【输出形式】输出3组结果，占3行，依次为36；24；12 24 36。

【样例输入】24 36 12

【样例输出】

36

24

12 24 36

【样例说明】三个整数 24、36、12中，最大值为36,；平均值为24；按由小到大排列的顺序为：12、24、36。

【评分标准】4个测试点，共20分。每个测试点5分。

【编程说明】本题必须使用类，在main()函数中创建对象，通过调用函数输入三个整数、计算并输出结果。非基于对象的程序不得分。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class COperation;

inline std::ostream &operator<<(std::ostream &out, const COperation &op);

class COperation
{
friend std::ostream &operator<<(std::ostream &out, const COperation &op);

private:
	std::vector<int> nums;

public:
	using value_type = int;
	using container_type = std::vector<int>;
public:
	COperation(std::vector<int> &&vec)
		: nums(vec)
	{
		this -> sort();
	}

	const double get_average()
	{
		value_type total = 0;
		for(value_type i : nums)
		{
			total += i;
		}
		return (double)total / nums.size();
	}

	const int get_max()
	{
		return nums.back(); 
	}

	COperation &sort()
	{
		std::sort(nums.begin(), nums.end());
		return *this;
	}
};

std::ostream &operator<<(std::ostream &out, const COperation &op)
{
	std::copy(op.nums.cbegin(), op.nums.cend(), std::ostream_iterator<COperation::value_type>(out, " "));
	return out;
}


int main(int argc, char **argv)
{
	std::vector<int> vec(0);
	std::istream_iterator<int> input_int(std::cin);
	for(size_t i = 0; i < 3; i++)
	{
		vec.emplace_back(*input_int);
		if(i != 2) input_int++;
	}
	COperation op(std::move(vec));
	std::cout << op.get_max() << std::endl <<  op.get_average() << std::endl << op << std::endl;
	return 0;	
}