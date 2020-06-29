#include <iostream>
#include<string>
using namespace std;
class myinter {
	friend ostream& operator<<(ostream& cout, myinter myint );
public:
	myinter() {
		m_num = 0;
	}
	myinter& operator++() {
		m_num++;
		return *this;
	}
	myinter operator(int) {
		myinter temp = *this;
		m_num++;
		return temp;
	}
private:
	int m_num;
};
ostream& operator<<(ostream& cout, myinter myint ) {
	cout << myint.m_num;
	return cout;
}
void test() {
	myinter myint;
	cout << myint << endl;
}

void test02() {

}


int main() {
	int a = 0;
	cout << ++a << endl;
	system("pause");
}