#include<iostream>
#include<string>
using namespace std;
//��ǰ�ñ�����֪����ģ��Ĵ���
template<class T1, class T2>class person;

template<class T1,class T2>
void printperson2(person<T1, T2>& p) {
	cout << "����ʵ��" << p.m_name << "����" << p.m_age << endl;
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
	//ȫ�ֺ��� ����ʵ��
	friend void printperson(person<T1, T2> &p)
	{
		cout << "����" << p.m_name << "����" << p.m_age << endl;
	}
	//ȫ�ֺ��� ����ʵ��
	//�ӿ�ģ��Ĳ����б�
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