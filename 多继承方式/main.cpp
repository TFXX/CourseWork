/*【问题描述】分别定义Teacher(教师)类和Cadre(干部)类，采用多重继承方式由这两个类派生出新类Teacher_Cadre(教师兼干部)。要求：

① 在两个基类中都包含姓名、出生日期(日期类Date的子对象)、性别等数据成员。

② 在Teacher类中还包含数据成员title(职称)，在Cadre类中还包含数据成员post(职务)， 在Teacher_Cadre类中还包含数据成员wages(工资)。

③ 对两个基类中的姓名、出生日期、性别等数据成员用相同的名字，在引用这些数据成员时，指定作用域。

    ④ 在类体中声明成员函数，在类外定义成员函数。

 ⑤ 在派生类Teacher_Cadre的成员函数show()中调用Teacher类中的display()函数，输出姓名、出生日期、性别、职称，然后再用cout语句输出职务与工资。设计main()完成测试。

【输入形式】无
【输出形式】派生类对象的各个数据成员的值，彼此以空格间隔。

【样例输入】无
【样例输出】LiHong 1967/10/12 f  professor Header 8000.00

【样例说明】以数据："LiHong",1967,10,12,'f',"professor","Header",8000.00初始化Teacher_Cadre类对象，在main()中测试show()函数输出有关数据。

【评分标准】本题50分，1个测试点。*/

#include <iostream>
#include <string>
#include <iomanip>

class Date
{
private:
    int year,month,day;
public:
    Date(int y, int m, int d);
    friend std::ostream &operator<<(std::ostream &out, const Date &);
};

std::ostream &operator<<(std::ostream &out, const Date &date)
{
    return out << date.year << "/" << date.month << "/" << date.day;
}

Date::Date(int y, int m, int d)
    : year(y), month(m), day(d)
{
    ;
}

class Teacher
{
private:
    std::string name;
    Date birthday;
    char sex;
    std::string title;
public:
    Teacher(const char *n, Date &&date, char s, const char *t);
    void display();
};

Teacher::Teacher(const char *n, Date &&date, char s, const char *t)
    : name(n), birthday(date), sex(s), title(t)
{
    ;
}

void Teacher::display()
{
    std::cout << name << " " << birthday << " " << sex << " " << title << " ";
}

class Cadre
{
private:
    std::string name;
    Date birthday;
    char sex;
    std::string post;
public:
    Cadre(const char *n, Date &&date, char s, const char *p);
    const std::string &get_post();
};

Cadre::Cadre(const char *n, Date &&date, char s, const char *p)
    : name(n), birthday(date), sex(s), post(p)
{
    ;
}

const std::string &Cadre::get_post()
{
    return post;
}

class Teacher_Cadre : public Teacher, public Cadre
{
private:
    double wages;
public:
    explicit Teacher_Cadre(const char *n, int y, int m, int d, char s, const char *t, const char *p, double w);
    void show();
};

Teacher_Cadre::Teacher_Cadre(const char *n, int y, int m, int d, char s, const char *t, const char *p, double w)
    : Teacher(n, Date(y, m, d), s, t), Cadre(n, Date(y, m ,d), s, p), wages(w)
{
    ;
}

void Teacher_Cadre::show()
{
    Teacher::display();
    std::cout << Cadre::get_post() << " " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << wages << " ";
}

int main(int argc, char **argv)
{
    Teacher_Cadre tc("LiHong",1967,10,12,'f',"professor","Header",8000.00);
    tc.show();
    return 0;
}