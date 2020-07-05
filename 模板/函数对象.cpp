using namespace std;
#include<iostream>
#include<string>
#include<deque>
class myadd {//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
public:

	int operator()(int v1, int v2) {
		return v1 + v2;
	
	}

};
void test() {
	myadd add;
	cout << add(10, 19) << endl;
}
//--------------------------------------------
class myprint {//2、函数对象可以有自己的状态
public:
	myprint() {
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}
	int count;
};
void test02() {
	myprint myPrint; 
	myPrint("hello world"); 
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint调用次数为： " << myPrint.count << endl;
}
void test03() {	// 3、函数对象可以作为参数传递
	myprint myprint;
	doprint(myprint, "hello");
}
void doprint(myprint& mp, string test) {
	mp(test);
}
int main() {
	test();
	test02();
}

