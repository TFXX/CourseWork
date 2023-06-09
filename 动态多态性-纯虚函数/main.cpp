/*
【问题描述】	要求正方体、球、圆柱的表面积，可以抽象出一个公共的基类Container为抽象类，在其中定义一个公共的数据成员radius(此数据可以作为正方形的边长、球的半径、圆柱体底面圆半径)，以及求表面积的纯虚函数area()。
			由此抽象类派生出要描述的三个类，利用基类指针和虚函数，分别计算三种图形的表面积。
			要求：在main()中，利用构造函数初始化三个派生类对象cube(6)、global(5)、cylinder(5,16)， 设计程序，依次测试三个派生类中计算表面积的area()函数功能。
			提示：圆周率取值3.14，结果保留两位小数。
【输入形式】无
【输出形式】依次输出三个派生类中指定对象的表面积。各数据用一个空格间隔。
【样例输入】没有输入。
【样例输出】216.00  314.00  659.40

【样例说明】cube对象的表面积为216.00；global对象的表面积为314.00；cylinder对象的表面积为659.40。
【评分标准】本题共35分，1个测试点。

【编程说明】本题必须在main()函数中按照给定的数值创建对象，依次输出cube对象、global对象、cylinder对象的表面积。未按照要求做不得分。
*/

#include <iostream>
#include <iomanip>
#include <vector>

class Container
{
public:
	double m_radius;
public:
	Container(double radius)
		: m_radius(radius)
	{
		;
	}

	virtual double get_surface() const = 0;

	static void print(const Container *container)
	{
		if(container != nullptr)
		{
			std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << container -> get_surface() << " ";
		}
	}
};

class Cube : public Container
{
public:
	Cube(double radius)
		: Container(radius)
	{
		;
	}

	double get_surface() const
	{
		return m_radius * m_radius * 6;
	}
};

class Global : public Container
{
public:
	Global(double radius)
		: Container(radius)
	{
		;
	}

	double get_surface() const
	{
		return m_radius * m_radius * 3.14 * 4;
	}	
};

class Cylinder : public Container
{
public:
	double m_h;
public:
	Cylinder(double radius, double h)
		: Container(radius), m_h(h)
	{
		;
	}

	double get_surface() const
	{
		return (m_radius * m_radius * 3.14) * 2 + (m_radius * 2 * 3.14) * m_h;
	}	
};

int main(int agrc, char **argv)
{
	Cube cube(6);
	Global global(5);
	Cylinder cylinder(5,16);

	Container::print(&cube);
	Container::print(&global);
	Container::print(&cylinder);
	return 0;
}