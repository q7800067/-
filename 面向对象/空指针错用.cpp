#include <iostream>
#include <string >
using namespace std;

class person {
public:
	void showclassname(){
		cout << "this is class" << endl;
		}
		void showperson() {
			cout << "age" <<m_age << endl;
		}
		int m_age;
};

void test01()
{
	person* p = NULL;
	p->showclassname();
	p->showperson();
}

int main() {

	test01();

	system("pause");

	return 0;
}