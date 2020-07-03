#include <iostream>
#include<string >
using namespace std;

template<class T1,class T2>
class person {
public:
	person(T1 name, T2 age) {
		this->m_name = name;
		this->m_age = age;
	}
	void showperson() {
		cout << "name" << this->m_name << "\t\tage" << this->m_age << endl;
	}
	T1 m_name;
	T2 m_age;
};
void printperson(person<string ,int>&p) {
	p.showperson();
}
template<class T1,class T3>
void printperson2(person<T1, T3>& p) {
	p.showperson();
}
template<class T>
void printperson3(T& p) {
	p.showperson();
	cou << "T的数据类型为：" << typeid(T).name();
}
void test01() {
	person<string, int >p("sun", 19);
	printperson(p);
}
void test02() {
	person<string, int>p("zhu", 29);
	printperson2(p);
}
void test03() {
	person<string, int>p("tang", 20);
	printperson3(p);
}




int main() {
	test03();
}