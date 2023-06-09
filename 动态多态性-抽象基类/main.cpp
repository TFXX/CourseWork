/*
【问题描述】  定义抽象基类Shape，由它派生出3个派生类：Circle(圆形)、Square(正方形)、Rectangle(矩形)。
            利用指针、虚函数printLength()、printArea()分别输出以上三者的面积和周长，三个图形的数据在定义对象时给定。
            另外实现一个通用的函数输出面积和周长，而不需要考虑是何种图形。
            要求：在main()中，利用构造函数初始化三个派生类对象cir(4)、squa(5)、rect(2,5)， 设计程序，依次测试三个派生类中printLength()、printArea()的功能。
            提示：圆周率取值3.14，结果保留两位小数。
【输入形式】无
【输出形式】输出占三行。每行依次为派生类中指定对象的周长、面积。各数据用空格间隔。
【样例输入】没有输入。
【样例输出】

       25.12  50.24

       20.00  25.00

       14.00  10.00
【样例说明】cir对象的周长为25.12，面积为50.24；squa对象的周长为20.00，面积为25.00；rect对象的周长为14.00，面积为10.00。
【评分标准】本题共35分，1个测试点。

【编程说明】本题必须在main()函数中按照给定的数值创建对象，依次输出cir对象的周长和面积、squa对象的周长和面积、rect对象的周长和面积。未按照要求做不得分。
*/

#include <iostream>
#include <iomanip>


class Shape
{
public:
    virtual double printLength() const = 0 ;
    virtual double printArea() const = 0;
    static void print(const Shape * shape)
    {
        if(shape != nullptr)
        {
            std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << shape -> printLength() << " " << shape -> printArea() << std::endl;
        }
    }
};



class Circle : public Shape
{
private:
    double m_r;
public:
    Circle(double r)
        : m_r(r)
    {
        ;
    }
    
    double printLength() const
    {
        return m_r * 3.14f * 2;
    }

    double printArea() const 
    {
        return m_r * m_r * 3.14f;
    }
};

class Square : public Shape
{
private:
    double m_a;
public:
    Square(double a)
        : m_a(a)
    {
        ;
    }

    double printLength() const 
    {
        return m_a * 4;
    }

    double printArea() const
    {
        return m_a * m_a;
    }
};

class Rectangle : public Shape
{
private:
    double m_a, m_b;
public:
    Rectangle(double a, double b)
        : m_a(a), m_b(b)
    {
        ;
    }

    double printLength() const
    {
        return 2 * (m_a + m_b);
    }

    double printArea() const 
    {
        return m_a * m_b;
    }
};

int main(int agrc, char **argv)
{
    Circle cir(4);
    Square squa(5);
    Rectangle rect(2, 5);
    
    Shape::print(&cir);
    Shape::print(&squa);
    Shape::print(&rect);
    return 0;
}