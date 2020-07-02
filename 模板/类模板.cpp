#include <iostream>
#include<string>
using namespace std;

template<class nametype,class agetype=int> //类模板可以有默认的参数
class person {
public:
	person(nametype name, agetype age) {
		this->m_name= name;
		this->m_age = age;
	}
	void showperson() {
		cout << "name=" << this->m_name << "\tage=" << this->m_age << endl;
	}
	nametype m_name;
	agetype m_age;

};


void test01() {
	person<string>p1("GY", 999);
	p1.showperson();
}
int main() {
	test01();
}