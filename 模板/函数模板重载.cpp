#include <iostream>
using namespace std;
#include<string>
class person {
public:
	person(string name, int age) {
		this->m_age = age;
		this->m_name = name;
	}
	string m_name;
	int m_age;
};
template<class T>
bool mycompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
template<>bool mycompare(person& p1, person& p2) {
	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age) {
		return true;
	}
	else {
		return false;
	}
}

void test01() {
	int a = 10;
	int b = 20;
	bool ret = mycompare(a, b);
	if (ret) {
		cout << "a=b" <<endl;
	}
	else {
		cout << "a!=b" << endl;
	}
}
void test02() {
	person p1("tom", 10);
	person p2("tom", 10);
	bool ret = mycompare(p1, p2);
	if (ret) {
		cout << "p1==p2" << endl;
	}
	else {
		cout << "p1!=p2" << endl;
	}
}



int main() {
	//test01();
	test02();
}