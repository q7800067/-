#include<iostream>
#include<string>
#include<vector>
using namespace std;
class person {
public:
	person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

void test() {
	vector<person*>v;
	person p1("aaa", 1);
	person p2("aaa", 2);
	person p3("aaa", 3);
	person p4("aaa", 4);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	/*for (vector<person>::iterator it = v.begin(); it != v.end();it++) {
		cout << "ÐÕÃû" << (*it).m_name << "  " << endl;
	}*/
	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ÐÕÃû" << (*it)->m_name << "ÄêÁä" << (*it)->m_age << endl;
	}

}


int main() {
	test();
}