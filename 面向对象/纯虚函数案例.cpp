#include<iostream>
#include <string>
using namespace std;
class abstractdrink {
public:
	virtual void boil() = 0;
	virtual void brew() = 0;
	virtual void pourincup() = 0;
	virtual void putsomething() = 0;
	void makedrink() {
		boil();
		brew();
		pourincup();
		putsomething();
	}
};
class coffee :public abstractdrink {
public:
	virtual void boil() {
		cout << "��ũ��ɽȪ" << endl;
	}
	virtual void brew() {
		cout << "���ݿ���" << endl;
	}
	virtual void pourincup() {
		cout << "���뱭��" << endl;
	}
	virtual void putsomething() {
		cout << "����ţ��" << endl;
	}
};
void dowork(abstractdrink *abs) {
	abs->makedrink();
	delete abs;
}
void test() {
	dowork(new coffee);
}


int main() {
	test();
}