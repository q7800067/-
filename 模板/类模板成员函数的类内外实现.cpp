#include<iostream>
#include<string>
using namespace std;
//提前让编译器知道类模板的存在
template<class T1, class T2>class person;

template<class T1,class T2>
void printperson2(person<T1, T2>& p) {
	cout << "类外实现" << p.m_name << "年龄" << p.m_age << endl;
}
template <class T1,class T2>
// -------------------------------------------------------
class person {
public:
		person(T1 name, T2 age) {
		this->m_name = name;
		this->m_age = age;
	}
public:
	//全局函数 类内实现
	friend void printperson(person<T1, T2> &p)
	{
		cout << "姓名" << p.m_name << "年龄" << p.m_age << endl;
	}
	//全局函数 类外实现
	//加空模板的参数列表
	 friend void printperson2<>(person<T1, T2>&p);
private:
	T1 m_name;
	T2 m_age;
};
// -------------------------------------------------------

void test() {
	person<string, int >p("tom", 20);
	printperson(p);
}
void test02()
{
	person <string, int >p("Jerry", 30);
	printperson2(p);
}
int main() {
	test();
	test02();
}