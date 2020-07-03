#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class person {
public:
	person(T1 name, T2 age);
	void showperson();
	T1 m_name;
	T2 m_age;
};

template<class T1,class T2>
person<T1, T2>::person(T1 name, T2 age) {
	this->m_name = name;
	this->m_age = age;
}

template<class T1,class T2>
void person<T1,T2>::showperson() {
	cout << "ÐÕÃû" << this->m_name << "ÄêÁä" << this->m_age << endl;
}
void test() {
	person<string, int >p("tom", 20);
	p.showperson();
}
int main() {
	test();
}