#include <iostream>
#include <string>
using namespace std;
class animal {
public:
	virtual void speak() = 0;

};
class Cat :public animal {
public:
	Cat(string name) {
		m_name  =new string(name);
	}
	virtual void speak() {
		cout <<*m_name<< "小猫在说话" << endl;
	}
	string* m_name;
};
void test() {
	animal* cat = new Cat("tom");
	cat->speak();
	delete cat;
}
int main() {
	test();
}