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


//const���ζ���  ������
void test01() {

	person p;
	p.showperson();

}
void test02() {
	const person p;
	p.m_a = 100;
	p.m_b = 299;
	p.abc(); //������ֻ�ܵ��ó�����
}
int main() {

	test01();

	system("pause");

	return 0;
}