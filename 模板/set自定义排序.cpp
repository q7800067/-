#include<iostream>
#include<string>
using namespace std;
#include<deque>
#include<set>
class person {
public:
	person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
class compare {
public:
	bool operator() (const person&p1,const person&p2){//�º���
		return p1.m_age > p2.m_age;
	}
};

void test() {
	set<person, compare>s;
	person p1("����", 23);
	person p2("����", 27);
	person p3("�ŷ�", 25);
	person p4("����", 21);
	s.insert(p1); 
	s.insert(p2); 
	s.insert(p3); 
	s.insert(p4);
	for (set<person>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "����" << it->m_name << "����" << it->m_age << endl;
	}
}
int mian() {
	test();
}