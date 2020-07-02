#include<iostream>
using namespace std;
void myprint(int a, int b) {
	cout << "调用的普通函数" << endl;
	}
template<class T>
void myprint(T a, T b) {
	cout << "调用模板" << endl;
}
void test01() {
	int a = 10;
	int b = 20;
	myprint(a, b);
	//通过控模板参数列表，强制调用函数模板
	myprint<>(a, b);
	char c1 = 'a';
	char c2 = 'b';
	myprint(a, b);  //优先调用模板，因为没有隐式类型转换
}
int main() {
	test01();
	system("pause");
	system("cls");
}