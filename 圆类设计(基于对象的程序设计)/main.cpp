/*
【问题描述】编写一个基于对象的程序：输入半径，计算圆的周长和面积并输出。实现提示：设计一个圆类，包括至少一个数据成员radius（圆的半径）；若干成员函数：计算周长的length( )，计算面积的area( )，输入半径的set()，输出有关数据的show()。设计main()函数，测试程序。
【输入形式】输入一个整数，表示圆的半径。
【输出形式】输出占一行，共2个数据。第1为圆的周长；第2个为圆的面积。保留2位小数(以小数形式输出的控制符为setiosflags(ios::fixed)，输出n位小数的控制符为setprecision(n)，需要打开“iomanip”头文件)。
【样例输入】10
【样例输出】62.80 314.00

【样例说明】半径为10的圆的周长和面积分别为62.80和314.00。

【评分标准】本题30分，共2个测试点，每个测试点15分。
【编程说明】本题必须使用类，在main()函数中创建对象，通过调用函数输入圆的半径、输出结果。非基于对象的程序不得分。
*/

#include <iostream>
#include <iomanip>
#include <iterator>

class CCircle
{
private:
	constexpr double static PI = 3.14;

	unsigned int m_radius;

public:
	CCircle(unsigned int radius)
		: m_radius(radius)
	{
		;
	}

	CCircle &set(unsigned int radius)
	{
		m_radius = radius;
		return *this;
	}


	const double length() const
	{
		return PI * 2 * m_radius;
	}

	const double area() const
	{
		return PI * m_radius * m_radius;
	}

	CCircle &show(std::ostream &out)
	{
		out << std::setiosflags(std::ios::fixed) << std::setprecision(2) << length() << " " << area();
		return *this;
	}
};

int main(int argc, char **argv)
{
	std::istream_iterator<unsigned int> input_uint(std::cin);
	CCircle circle(*input_uint);
	circle.show(std::cout);
	return 0;
}