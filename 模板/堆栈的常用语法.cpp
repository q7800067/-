#include<iostream>
#include<string>
using namespace std;
#include<stack>
void test() {
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	while (s.empty()) {
		cout << "ջ��Ԫ��Ϊ" << s.top() << endl;
		s.pop();
	}
	cout << "ջ�Ĵ�СΪ" << s.size() << endl;
}

int main() {
	test();
}


















