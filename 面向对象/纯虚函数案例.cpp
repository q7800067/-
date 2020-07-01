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
		cout << "ÖúÅ©¸±É½Èª" << endl;
	}
	virtual void brew() {
		cout << "³åÅÝ¿§·È" << endl;
	}
	virtual void pourincup() {
		cout << "µ¹Èë±­ÖÐ" << endl;
	}
	virtual void putsomething() {
		cout << "µ¹ÈëÅ£ÄÌ" << endl;
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