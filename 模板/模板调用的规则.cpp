#include<iostream>
using namespace std;
void myprint(int a, int b) {
	cout << "���õ���ͨ����" << endl;
	}
template<class T>
void myprint(T a, T b) {
	cout << "����ģ��" << endl;
}
void test01() {
	int a = 10;
	int b = 20;
	myprint(a, b);
	//ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
	myprint<>(a, b);
	char c1 = 'a';
	char c2 = 'b';
	myprint(a, b);  //���ȵ���ģ�壬��Ϊû����ʽ����ת��
}
int main() {
	test01();
	system("pause");
	system("cls");
}