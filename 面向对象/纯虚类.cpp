#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	virtual void func() = 0;
};
class son :public Base{
public:
	 void func() {
		cout << "func��������" << endl;
	}
};
class son1 :public Base{
public:
	 void func() {
		cout << "func��������" << endl;
	}
};
void test() {
	Base* base = new son;
	Base->func();
	Base* base = new son1;
	Base->func();
}

int main() {
	test();
}