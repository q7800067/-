using namespace std;
#include<iostream>
#include<string>
#include<deque>
class myadd {//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
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
class myprint {//2����������������Լ���״̬
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
	cout << "myPrint���ô���Ϊ�� " << myPrint.count << endl;
}
void test03() {	// 3���������������Ϊ��������
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

