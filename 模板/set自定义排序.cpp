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
	bool operator() (const person&p1,const person&p2){//仿函数
		return p1.m_age > p2.m_age;
	}
};

void test() {
	set<person, compare>s;
	person p1("刘备", 23);
	person p2("关羽", 27);
	person p3("张飞", 25);
	person p4("赵云", 21);
	s.insert(p1); 
	s.insert(p2); 
	s.insert(p3); 
	s.insert(p4);
	for (set<person>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "姓名" << it->m_name << "年龄" << it->m_age << endl;
	}
}
int mian() {
	test();
}