#include  <iostream>
#include <string >
using namespace std;
void swap1(int a,int b) {//ֵ����
	int temp = a;
	b = a;
	a = temp;
}
void swap2(int *a,int *b) {//��ַ����
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap3(int& a, int& b) {//���ô���
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int a = 10;
	int b = 20;
	//swap1(a, b);
	//swap2(&a, &b);
	swap3(a, b);
	cout << "a=" << a<<endl;
	cout << "b=" << b<<endl;
	system("pause");
}