#include <iostream>
#include <string >
using namespace std;
class person {
public:
	void showperson() const {
		this->m_b = 100;
	}
	void abc() {

	}
	int m_a;
	mutable int m_b;
};


//const修饰对象  常对象
void test01() {

	person p;
	p.showperson();

}
void test02() {
	const person p;
	p.m_a = 100;
	p.m_b = 299;
	p.abc(); //常对象只能调用常函数
}
int main() {

	test01();

	system("pause");

	return 0;
}