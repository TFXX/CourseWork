/*
【问题描述】	定义Point类描述点，并加入一个友元函数计算两点间距离。
			利用Point类设计描述圆的Circle类，包括圆心（Point类的点）、半径，构造函数初始化圆，成员函数判断某个点m是否在圆周上。
			设计main()函数，以(1,2)为圆心、5为半径、m为(6,2)进行测试。

【输入形式】无。使用构造函数进行初始化。
【输出形式】输出为1或0，表示m点是否在指定圆周上的判断结果。1表示m点在指定圆周上；0表示m点不在圆周上。

【样例输入】无
【样例输出】1
【样例说明】main()函数中，以(1,2)为圆心、5为半径创建圆对象，通过调用判断点是否在圆周上的函数，得到结论：m(6,2)点在圆周上。

【评分标准】本题1个测试点，共30分。

【编程说明】本题必须在main()函数中按照给定的数值创建对象，输出判断点是否在圆周上的结果。未按照要求做不得分。
*/

#include <iostream>
#include <cmath>

class Point
{
private:
	int m_x, m_y;
public:
	Point(int x, int y)
		: m_x(x), m_y(y)
	{
		;
	}
	
	int operator-(const Point &other) const
	{
		return (this->m_x - other.m_x) * (this->m_x - other.m_x) +(this->m_y - other.m_y) * (this->m_y - other.m_y);
	}
};

class Circle
{
private:
	Point m_center;
	int m_radius;
public:
	Circle(const Point &center, int radius)
		: m_center(center), m_radius(radius)
	{
		;
	}

	bool is_on_boundary(const Point &p)
	{
		return m_radius * m_radius == p - m_center;
	}
};

int main(int argc, char **argv)
{
	Circle cir(Point(1, 2), 5);
	if(cir.is_on_boundary(Point(6, 2)))
		std::cout << "1";
	else
		std::cout << "0";

	return 0;
};