/*
【问题描述】动态建立一个对象数组，包含5个学生的数据(学号、1门成绩)。利用指向数组的指针，统计平均成绩并输出第1、3、5个学生的数据。
【输入形式】输入由成员函数完成。依次输入5个学生的学号和成绩。各数据用空格间隔。
【输出形式】输出占4行。第一行为平均成绩；以下三行为第1、3、5个学生的数据。保留小数点后2位。
【样例输入】1001 90.5 1002 86.0 1003 92.5 1004 98.0 1005 80
【样例输出】89.40

            1001 90.50

            1003 92.50

            1005 80.00
【样例说明】5个学生的学号和成绩分别为：1001、90.5；1002、86；1003、92.5；1004、98.0；1005、80。平均成绩为89.40；第1、3、5个学生的数据为：1001、90.50；1003、92.50；1005、80.00。
【评分标准】本题共10分，2个测试点，每个测试点5分。

【编程说明】本题必须使用类，在main()函数中创建对象。非基于对象的程序不得分。
*/

#include <iostream>
#include <iomanip>
#include <string>

class CStu
{
public:
    double static get_avg_grade(const CStu *pStu, const size_t num)
    {
        double total = 0;
        for(size_t i = 0; i < num; i++)
        {
           total += pStu[i].get_grade();
        }
        return total / num;
    }

    void static input(CStu *pStu, const size_t num)
    {
        for(size_t i = 0; i < 5; i++)
        {
            std::cin >> pStu[i].m_id >> pStu[i].m_grade;
        }
    }

    double get_grade() const
    {
        return m_grade;
    }

    const std::string &get_id() const
    {
        return m_id;
    }

private:
    std::string m_id;
    double m_grade = 0.0f;
};

int main(int argc, char **argv)
{
    CStu *a = new CStu[5];
    CStu::input(a, 5);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) 
        << CStu::get_avg_grade(a, 5) << '\n'
        << a[0].get_id() << ' ' << a[0].get_grade() << '\n' 
        << a[2].get_id() << ' ' << a[2].get_grade() << '\n' 
        << a[4].get_id() << ' ' << a[4].get_grade() << std::endl;
	return 0;
}