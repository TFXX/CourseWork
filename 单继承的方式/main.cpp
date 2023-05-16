/*【问题描述】人员类是抽象程度更高的类，它是所有人的共性的抽象。现声明一个人员类（Person ），
包括3个数据成员：name（姓名）、age（年龄）、sex（性别）；2个成员函数：构造函数和输出相关信息的函数display()。
利用单继承的方式声明一个学生（Student）派生类，其中增加2个数据成员：grade（年级）、score（总学分）；3个成员函数：构造函数、输出函数show()和增加学分的函数add()。
add()原型为：void add(float s)，其中，s表示某门课的学分，将s加入到总学分score中。
要求：在main()中定义派生类对象，初始化的数据为：姓名"Xu Li"，年龄20，性别'f'，年级2，总学分25.4，某门课的学分为2.6，按照要求测试show()、add()函数。

【输入形式】无
【输出形式】派生类对象的各个数据成员的值，彼此以空格间隔。

【样例输入】无
【样例输出】Xu Li 20 f 2 28

【样例说明】以给定的值初始化派生类对象，调用add()和show()，调整学分并输出姓名、年龄、性别、年级、总学分。
【评分标准】本题50分，1个测试点。*/
#include <iostream>
#include <string>
class Person
{
private:
	std::string name;
	int age;
	char sex;
public:
	Person(const char *n, int a, char s)
		: name(n), age(a), sex(s)
	{
		
	}

	void display()
	{
		std::cout << name << " " << age << " "<< sex << " ";
	}
};

class Student : public Person
{
private:
	int grade;
	float score;
public:
	Student(const char *n, int a, char s, int g, float sc)
		: Person(n, a, s), grade(g), score(sc)
	{
		;
	}

	Student &add(float s)
	{
		score += s;
		return *this;
	}

	void show()
	{
		Person::display();
		std::cout << grade << " " << score << " ";
	}
};

int main(int argc, char **argv)
{
	Student s("Xu Li", 20, 'f', 2, 25.4f);
	s.add(2.6f).show();
	return 0;
}