#include<iostream>
#include<string>
using namespace std;
#include<queue>
#include<list>
class person {
public:
	person(string name, int age, int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;
};
bool compare(person&p1,person&p2) {
	if (p1.m_age == p2.m_age) {
		return p1.m_height > p2.m_height;
	}
	else{ return p1.m_age < p2.m_age; }
}
void test() {
	list<person>L;
	person p1("����", 35, 175);
	person p2("�ܲ�", 45, 180);
	person p3("��Ȩ", 40, 170);
	person p4("����", 25, 190);
	person p5("�ŷ�", 35, 160);
	person p6("����", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	for (list<person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "����" <<(*it).m_name << "����" << it->m_age << "���"
				<< it->m_height << endl;
	}
	cout << "�����" << endl;
	L.sort(compare);
	for (list<person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "����" << (*it).m_name << "����" << it->m_age << "���"
			<< it->m_height << endl;
	}
}
int main() {
	test();
}